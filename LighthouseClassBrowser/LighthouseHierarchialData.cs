using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EnvDTE;

namespace LighthouseClassBrowser
{
    namespace HierarchialData
    {
        public class Project 
        {
            public string m_ProjectName { get; private set; }
            private readonly EnvDTE.Project m_Project;
            public List<SourceFile> m_SourceFile { get; private set; }

            public Project(EnvDTE.Project project)
            {
                m_ProjectName = project.FullName;
                m_Project = project;
                setProjectItemsRecursive(m_Project.ProjectItems);
            }

            public void setProjectItemsRecursive(ProjectItems items)
            {
                if (items.Count == 0)
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

        public class SourceFile
        {
            public EnvDTE.ProjectItem m_ProjectItem { get; private set; }
            public string m_FileName { get; private set; }
            public List<Class> m_Classes { get; private set; }

            internal SourceFile(EnvDTE.ProjectItem item)
            {
                m_ProjectItem = item;
                m_FileName = item.Name;
                setClassesRecursive(m_ProjectItem);
            }

            public void setClassesRecursive(ProjectItem item)
            {
                if (m_ProjectItem.FileCodeModel.CodeElements.Count == 0)
                    return;

                foreach (CodeElement element in m_ProjectItem.FileCodeModel.CodeElements)
                {
                   if(isClassType(element.Kind))
                        m_Classes.Add(new Class(element.ProjectItem));
                   else
                        setClassesRecursive(element.ProjectItem);
                }
            }

            private bool isClassType(vsCMElement kind)
            {
                return (kind == vsCMElement.vsCMElementClass || kind == vsCMElement.vsCMElementInterface);
            }
        }

        public class Class
        {
            public string m_ClassName { get; private set; }
            public EnvDTE.ProjectItem m_ProjectItem { get; private set; }
            public List<Method> m_Methods { get; private set; }
            public List<Variable> m_Variable { get; private set; }

            internal Class(ProjectItem item)
            {
                m_ClassName = item.Name;
                m_ProjectItem = item;
                setClassComponents(item);
            }

            public void setClassComponents(ProjectItem item)
            {
                if (item.FileCodeModel.CodeElements.Count == 0)
                    return;
                foreach (CodeElement element in item.FileCodeModel.CodeElements)
                {
                   if(element.Kind == vsCMElement.vsCMElementFunction)
                        m_Methods.Add(new Method(element.ProjectItem)); 
                   else if(element.Kind == vsCMElement.vsCMElementVariable)
                        m_Variable.Add(new Variable(element.ProjectItem));
                } 
            }
        }

        public class Method
        {
            public string m_Name { get; private set; }
            public EnvDTE.ProjectItem m_ProjectItem;
            
            public Method(ProjectItem item)
            {
                m_Name = item.Name;
                m_ProjectItem = item;
            }
        }

        public class Variable
        {
            public string m_Name { get; private set; }
            public EnvDTE.ProjectItem m_ProjectItem;

            public Variable(ProjectItem item)
            {
                m_ProjectItem = item;
                m_Name = item.Name;
            }
        }
    }
}
