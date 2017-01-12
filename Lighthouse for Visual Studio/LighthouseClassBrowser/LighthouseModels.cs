using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using EnvDTE;
using EnvDTE80;
using Microsoft.VisualStudio.PlatformUI;

namespace LighthouseClassBrowser
{
    internal class ProjectBrowserModel
    {
        internal ProjectBrowserModel(LighthouseControl lighthouseControl, ClassBrowserModel classBrowserModel)
        {
            m_ListBoxProjectView = lighthouseControl.ListBoxProjectBrowser;
            m_ClassBrowserModel = classBrowserModel;
        }

        internal void eventProjectChanged(List<HierarchialData.Project> projects)
        {
            var list = new List<HierarchialData.Item>();
            foreach (HierarchialData.Project project in projects)
                list.Add((HierarchialData.Item) project);

            setProjects(list);
            updateView();
        }

        internal void eventSelectionChanged(List<HierarchialData.Item> selectedItems)
        {
            var sourceFiles = new List<HierarchialData.Item>();
            var selectedFiles = new List<HierarchialData.Item>();

            foreach (HierarchialData.Item item in selectedItems)
            {
                if (item.GetType() == typeof(HierarchialData.SourceFile))
                {
                    var sourceFile = item as HierarchialData.SourceFile;

                    sourceFile.setClassesRecursive(sourceFile.m_ProjectItem.FileCodeModel.CodeElements);
                    sourceFiles.Add(item);
                    selectedFiles.Add(item);
                }
            }

            m_SelectedItems = selectedFiles;

            m_ClassBrowserModel.eventProjectSelectionChanged(sourceFiles);
            updateView();
        }

        private void setProjects(List<HierarchialData.Item> items)
        {
            foreach (HierarchialData.Item item in items)
            {
                var project = item as HierarchialData.Project;
                project.setProjectItemsRecursive(project.m_Project.ProjectItems);
            }

            m_OpenProjects = items;
        }

        private void updateView()
        {
            var list = new List<HierarchialData.Item>();
            foreach (HierarchialData.Item item in m_OpenProjects)
            {
                list.Add(item);
                if (item.GetType() == Lighthouse.TypeOfProject)
                {
                    var project = item as HierarchialData.Project;
                    list.AddRange(project.m_SourceFile);
                }
            }

            m_ListBoxProjectView.DataContext = new List<HierarchialData.Item>(list); 
        }

        private List<HierarchialData.Item> m_OpenProjects;
        public List<HierarchialData.Item> m_SelectedItems { get; private set; }
        private readonly ListBox m_ListBoxProjectView;
        private readonly ClassBrowserModel m_ClassBrowserModel;
    }

    internal class ClassBrowserModel
    {
        internal ClassBrowserModel(LighthouseControl lighthouseControl, MethodBrowserModel methodBrowserModel,
            VariableBrowserModel variableBrowserModel)
        {
            m_ClassListBox = lighthouseControl.ListBoxClassBrowser;
            m_ButtonAbstract = lighthouseControl.ButtonClassAbstract;
            m_ButtonDerived = lighthouseControl.ButtonClassDerived;
            m_ButtonStatic = lighthouseControl.ButtonClassStatic;

            m_MethodBrowserModel = methodBrowserModel;
            m_VariableBrowserModel = variableBrowserModel;
        }

        internal void eventProjectSelectionChanged(List<HierarchialData.Item> selectedSourceFiles)
        {
            var list = new List<HierarchialData.Item>();
            foreach (HierarchialData.Item sourceFile in selectedSourceFiles)
            {
                var classItems = (sourceFile as HierarchialData.SourceFile).m_Classes;
                list.AddRange(classItems);
            }

            updateView(list);
        }

        internal void eventButtonAbstractPressed()
        {
            updateView();
        }

        internal void eventClassSelectionChanged(List<HierarchialData.Item> selectedClasses)
        {
            setClassesRecursive(selectedClasses);

            m_MethodBrowserModel.eventClassSelectionChanged(selectedClasses);
            m_VariableBrowserModel.eventClassSelectionChanged(selectedClasses);
        }

        private void setClassesRecursive(List<HierarchialData.Item> selectedClasses)
        {
            foreach (HierarchialData.Item item in selectedClasses)
            {
                var classItem = item as HierarchialData.Class;
                classItem.setClassComponents(classItem.m_CodeElement);
            }
        }

        private void updateView(List<HierarchialData.Item> items)
        {
            m_ClassListBox.DataContext = new List<HierarchialData.Item>(
                ButtonsStateHandler(items)
                );
        }

        private List<HierarchialData.Item> ButtonsStateHandler(List<HierarchialData.Item> items)
        {
            if (m_ButtonAbstract.IsChecked == true)
            {
                return hideAbstract(items);
            }
            if (m_ButtonDerived.IsChecked == true)
            {
                
            }
            if (m_ButtonStatic.IsChecked == true)
            {
                
            }
            return items;
        }

        private List<HierarchialData.Item> hideAbstract(List<HierarchialData.Item> items)
        {
            var list = new List<HierarchialData.Item>();
            foreach (HierarchialData.Item item in items)
            {
                if(!isAbstract(((item as HierarchialData.Class).m_CodeElement as CodeClass2).Access))
                {
                    list.Add(item);
                }
            }
            return list;
        }

        private bool isAbstract(vsCMAccess accessLevel)
        {
            return accessLevel == vsCMAccess.vsCMAccessPublic
                   || accessLevel == vsCMAccess.vsCMAccessDefault;
        }

        private ListBox m_ClassListBox;
        private ToggleButton m_ButtonAbstract;
        private ToggleButton m_ButtonDerived;
        private ToggleButton m_ButtonStatic;
        private MethodBrowserModel m_MethodBrowserModel;
        private VariableBrowserModel m_VariableBrowserModel;
    }

    internal class MethodBrowserModel
    {
        internal MethodBrowserModel(LighthouseControl lighthouseControl)
        {
            m_MethodListBox = lighthouseControl.ListBoxMethodBrowser;
            m_ButtonAbstract = lighthouseControl.ButtonMethodAbstract;
            m_ButtonDerived = lighthouseControl.ButtonMethodDerived;
            m_ButtonStatic = lighthouseControl.ButtonClassStatic;
        }

        internal void eventClassSelectionChanged(List<HierarchialData.Item> selectedClasses)
        {
            var list = new List<HierarchialData.Item>();
            
            foreach (HierarchialData.Class classItem in selectedClasses)
                list.AddRange(classItem.m_Methods);

            updateView(list);
        }

        private void updateView(List<HierarchialData.Item> variables)
        {
            m_MethodListBox.DataContext = new List<HierarchialData.Item>(variables);
        }

        internal void eventButtonAbstractPressed()
        {
            
        }

        private ListBox m_MethodListBox;
        private ToggleButton m_ButtonAbstract;
        private ToggleButton m_ButtonDerived;
        private ToggleButton m_ButtonStatic;
    }

    internal class VariableBrowserModel
    {
        internal VariableBrowserModel(LighthouseControl lighthouseControl)
        {
            m_VariableListBox = lighthouseControl.ListBoxVariableBrowser;
            m_ButtonAbstract = lighthouseControl.ButtonVariableAbstract;
            m_ButtonDerived = lighthouseControl.ButtonVariableDerived;
            m_ButtonStatic = lighthouseControl.ButtonVariableStatic;
        }

        internal void eventClassSelectionChanged(List<HierarchialData.Item> selectedClasses)
        {
            var list = new List<HierarchialData.Item>();
            
            foreach (HierarchialData.Class classItem in selectedClasses)
                list.AddRange(classItem.m_Variable);

            updateView(list);
        }

        private void updateView(List<HierarchialData.Item> variables)
        {
            m_VariableListBox.DataContext = new List<HierarchialData.Item>(variables);
        }

        internal void eventButtonAbstractPressed()
        {
            
        }

        private ToggleButton m_ButtonAbstract;
        private ToggleButton m_ButtonDerived;
        private ToggleButton m_ButtonStatic;
        private ListBox m_VariableListBox;
    }
}
