using System;
using System.Collections.Generic;
using System.Reflection;
using System.Windows.Data;
using EnvDTE;

namespace LighthouseClassBrowser
{
    namespace HierarchialData
    {
        public class Item
        {
        }

        public class Project : Item
        {
            private readonly EnvDTE.Project m_Project;
            public string m_Name { get; private set; }
            public List<SourceFile> m_SourceFile { get; private set; }

            public Project(EnvDTE.Project project)
            {
                m_SourceFile = new List<SourceFile>();
                m_Name = project.Name;
                m_Project = project;
                setProjectItemsRecursive(m_Project.ProjectItems);
            }

            public void setProjectItemsRecursive(ProjectItems items)
            {
                if (items == null  || items.Count == 0)
                    return;

                foreach (EnvDTE.ProjectItem item in items)
                {
                    if (item.Name.Contains(".cs"))
                        m_SourceFile.Add(new SourceFile(item));
                    else
                        setProjectItemsRecursive(item.ProjectItems);
                }
            }
        };

        public class SourceFile : Item
        {
            public EnvDTE.ProjectItem m_ProjectItem { get; private set; }
            public string m_Name { get; private set; }
            public List<Class> m_Classes { get; private set; }

            internal SourceFile(EnvDTE.ProjectItem item)
            {
                m_Classes = new List<Class>();
                m_ProjectItem = item;
                m_Name = "   " + item.Name; // the space is added because of the hierarchial presentation in the listbox
                if (item.FileCodeModel != null && item.FileCodeModel.CodeElements.Count != 0)
                    setClassesRecursive(item.FileCodeModel.CodeElements);
            }

            public void setClassesRecursive(CodeElements elements)
            {
                foreach (CodeElement subElement in elements)
                {
                    if(isClassType(subElement.Kind))
                        m_Classes.Add(new Class(subElement));
                    else if(isNamespaceType(subElement.Kind)) 
                        setClassesRecursive(subElement.Children);
                }
            }

            private bool isNamespaceType(vsCMElement kind)
            {
                return kind == vsCMElement.vsCMElementNamespace;
            }
            private bool isClassType(vsCMElement kind)
            {
                return (kind == vsCMElement.vsCMElementClass || kind == vsCMElement.vsCMElementInterface);
            }
        }

        public class Element : Item
        {
            public virtual EnvDTE.CodeElement m_CodeElement { get; protected set; }
        }

        public class Class : Element
        {
            public string m_Name { get; private set; }
            public override EnvDTE.CodeElement m_CodeElement { get; protected set; }
            public List<Method> m_Methods { get; private set; }
            public List<Variable> m_Variable { get; private set; }

            internal Class(CodeElement element)
            {
                m_Methods = new List<Method>();
                m_Variable = new List<Variable>();
                m_Name = element.Name;
                m_CodeElement = element;
                setClassComponents(element);
            }

            public void setClassComponents(CodeElement element)
            {
                if (element  == null)
                    return;
                if (element.Children.Count == 0)
                    return;

                foreach (CodeElement subElement in element.Children)
                {
                    if (subElement.Kind == vsCMElement.vsCMElementFunction)
                        m_Methods.Add(new Method(subElement));
                    else if (subElement.Kind == vsCMElement.vsCMElementVariable)
                        m_Variable.Add(new Variable(subElement));
                }
            }
        }

        public class Method : Element 
        {
            public string m_Name { get; private set; }
            public override EnvDTE.CodeElement m_CodeElement { get; protected set; }
            
            public Method(CodeElement element)
            {
                m_Name = element.Name;
                m_CodeElement = element;
            }
        }

        public class Variable : Element
        {
            public string m_Name { get; private set; }
            public override EnvDTE.CodeElement m_CodeElement { get; protected set; }

            public Variable(CodeElement element)
            {
                m_CodeElement = element;
                m_Name = element.Name;
            }
        }
    }
}
