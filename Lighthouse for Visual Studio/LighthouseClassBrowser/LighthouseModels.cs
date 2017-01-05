using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using EnvDTE;
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
            foreach(HierarchialData.Project project in projects)
                project.setProjectItemsRecursive(project.m_Project.ProjectItems);

            updateView(projects);
        }
        internal void eventSelectionChanged(List<HierarchialData.Item> selectedItems)
        {
            var sourceFiles = new List<HierarchialData.Item>();

            foreach (HierarchialData.Item item in selectedItems)
            {
                if (item.GetType() == typeof(HierarchialData.SourceFile))
                {
                    var sourceFile = item as HierarchialData.SourceFile;

                    sourceFile.setClassesRecursive(sourceFile.m_ProjectItem.FileCodeModel.CodeElements);
                    sourceFiles.Add(item);
                }
            }
            m_ClassBrowserModel.eventProjectSelectionChanged(sourceFiles);
            updateView(sourceFiles);
        }

        private void updateView(List<HierarchialData.Item> items)
        {
            m_ListBoxProjectView.DataContext = new List<HierarchialData.Item>(items); 
        }
        private void updateView<T>(List<T> items) where T : HierarchialData.Project //pure
        {
            var itemList = new List<HierarchialData.Item>();

            foreach (T project in items)
            {
                itemList.Add(project);

                foreach (HierarchialData.SourceFile file in project.m_SourceFile)
                    itemList.Add(file);
            }
            m_ListBoxProjectView.DataContext = new List<HierarchialData.Item>(items);
        }

        private List<HierarchialData.SourceFile> selectedSourceFiles;
        private ListBox m_ListBoxProjectView;
        private ClassBrowserModel m_ClassBrowserModel;
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

        internal void eventClassSelectionChanged(List<HierarchialData.Item> selectedClasses)
        {
            foreach (HierarchialData.Item item in selectedClasses)
            {
                
            }
        }

        private void updateView(List<HierarchialData.Item> items)
        {
            m_ClassListBox.DataContext = new List<HierarchialData.Item>(items);
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

        private ToggleButton m_ButtonAbstract;
        private ToggleButton m_ButtonDerived;
        private ToggleButton m_ButtonStatic;
        private ListBox m_VariableListBox;
    }
}
