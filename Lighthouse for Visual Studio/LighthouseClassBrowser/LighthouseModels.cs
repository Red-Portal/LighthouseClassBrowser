using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;

namespace LighthouseClassBrowser
{
    internal class ProjectBrowserModel
    {
        internal ProjectBrowserModel(LighthouseControl lighthouseControl, ClassBrowserModel classBrowserModel)
        {
            m_ListBoxProject = lighthouseControl.ListBoxProjectBrowser;
            m_ClassBrowserModel = classBrowserModel;
        }

        internal void updateView(HierarchialData.Project projects)
        {
            
        }

        private ListBox m_ListBoxProject;
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
