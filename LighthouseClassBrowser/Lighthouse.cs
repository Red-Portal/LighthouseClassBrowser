//------------------------------------------------------------------------------
// <copyright file="Lighthouse.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System.IO.Packaging;
using System.Runtime.CompilerServices;
using Microsoft.VisualStudio.Text.Editor;
using Microsoft.VisualStudio.TextManager.Interop;

namespace LighthouseClassBrowser
{
    using System;
    using System.Runtime.InteropServices;
    using Microsoft.VisualStudio.Shell;
    using Microsoft.VisualStudio.Text;
    using  Microsoft.VisualStudio.Editor;
    using EnvDTE;
    using System.Collections.Generic;

    /// <summary>
    /// This class implements the tool window exposed by this package and hosts a user control.
    /// </summary>
    /// <remarks>
    /// In Visual Studio tool windows are composed of a frame (implemented by the shell) and a pane,
    /// usually implemented by the package implementer.
    /// <para>
    /// This class derives from the ToolWindowPane class provided from the MPF in order to use its
    /// implementation of the IVsUIElementPane interface.
    /// </para>
    /// </remarks>
    [Guid("2b98fb5b-0cf9-402a-817a-5dbf39aa3760")]
    class Lighthouse : ToolWindowPane
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="Lighthouse"/> class.
        /// </summary>
        public Lighthouse() : base(null)
        {
            this.Caption = "Lighthouse";

            // This is the user control hosted by the tool window; Note that, even if this class implements IDisposable,
            // we are not calling Dispose on this object. This is because ToolWindowPane calls Dispose on
            // the object returned by ent property.
            this.Content = new LighthouseControl(this);
            m_LighthouseControl = (LighthouseControl) this.Content;
             
            m_EditorViewControl = new EditorViewControl(
                (IVsTextManager) serviceProvider.GetService(typeof(SVsTextManager)), this.Content
                );
            m_projects = new List<HierarchialData.Project>();
            var serviceDTE = serviceProvider.GetService(typeof(DTE)) as DTE;

            if (serviceDTE != null)
                setProjects(serviceDTE.Solution.Projects);
        }

        private LighthouseControl m_LighthouseControl;
        internal List<HierarchialData.Project> m_projects { get; private set; }
        private EditorViewControl m_EditorViewControl;

        internal void eventSelectedVariable()
        {
            
        }

        internal void eventSelectedMethod()
        {
            
        }

        internal void eventSelectedClass()
        {
            
        }

        private void setProjects(Projects projects)
        {
            if (projects == null)
                return;

            foreach (Project project in projects)
            {
                m_projects.Add(new HierarchialData.Project(project));
            }
        }

        /// 
        private static Package m_Package;

        /// <summary>
        /// Static method for setting ServiceProvider regardless of whether Lighthouse is instantiated or not.
        /// </summary>
        /// <param name="package"></param>
        public static void setPackage(Package package)
        {
            Lighthouse.m_Package = package;
        }

        ///

        private IServiceProvider serviceProvider //external initialization of static variable ServiceProvider
        {
            get { return Lighthouse.m_Package; }
        }
        
        // a 'Package' is a term meaning the hierarchy just higher than Classes
    }
}