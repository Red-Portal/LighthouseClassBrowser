//------------------------------------------------------------------------------
// <copyright file="LighthouseControl.xaml.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System.Collections.Generic;
using EnvDTE;

namespace LighthouseClassBrowser
{
    using System.Diagnostics.CodeAnalysis;
    using System.Windows;
    using System.Windows.Controls;

    /// <summary>
    /// Interaction logic for LighthouseControl.
    /// </summary>
    public partial class LighthouseControl : UserControl
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="LighthouseControl"/> class.
        /// </summary>
        internal LighthouseControl(Lighthouse lighthouse)
        {
            this.InitializeComponent();
            m_Lighthouse = lighthouse;
        }

        private Lighthouse m_Lighthouse;

        internal void showProjects(List<HierarchialData.Project> projects)
        {
            var ProjectList = new List<HierarchialData.Project>();
            foreach (HierarchialData.Project project in projects)
            {
                ProjectList.Add(project);
            }
            this.ListBoxClassBrowser.DataContext = new List<HierarchialData.Project>(ProjectList);
        }

        internal void showClasses()
        {
            
        }

        internal void showMethods()
        {
            
        }

        internal void getVariables()
        {
            
        }
    }
}