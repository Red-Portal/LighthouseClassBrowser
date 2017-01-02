﻿//------------------------------------------------------------------------------
// <copyright file="Lighthouse.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System.IO.Packaging;
using System.Runtime.CompilerServices;
using EnvDTE80;
using Microsoft.VisualStudio.Shell.Interop;
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
             
      
            m_ServiceDTE = serviceProvider.GetService(typeof(DTE)) as DTE;
            
            if (m_ServiceDTE == null)
                return;

            m_Events = ((Events2) m_ServiceDTE.Events).SolutionEvents;
            m_Events.Opened += new _dispSolutionEvents_OpenedEventHandler(eventOnSolutionOpen);
            m_Events.ProjectRenamed += new _dispSolutionEvents_ProjectRenamedEventHandler(eventOnProjectRename);
            m_Events.ProjectAdded += new _dispSolutionEvents_ProjectAddedEventHandler(eventOnProjectAdded);
            m_Events.ProjectRemoved += new _dispSolutionEvents_ProjectRemovedEventHandler(eventOnProjectRemoved);

            if(m_ServiceDTE.Solution.IsOpen)
                setProjects(m_ServiceDTE.Solution.Projects);
        }


        private SolutionEvents m_Events;
        private static Package m_Package;
        private readonly EnvDTE.DTE m_ServiceDTE;
        private LighthouseControl m_LighthouseControl;
        internal List<HierarchialData.Project> m_projects { get; private set; }
        private EditorViewControl m_EditorViewControl;

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
       
        private void eventOnSolutionOpen()
        {
            m_EditorViewControl = new EditorViewControl(
                (IVsTextManager) serviceProvider.GetService(typeof(SVsTextManager)), this.Content
                );
            setProjects(m_ServiceDTE.Solution.Projects);
        }
        private void eventOnProjectRename(Project project, string name)
        {
            setProjects(m_ServiceDTE.Solution.Projects);
        }
        private void eventOnProjectAdded(Project project)
        {
            setProjects(m_ServiceDTE.Solution.Projects);
        }
        private void eventOnProjectRemoved(Project project)
        {
            setProjects(m_ServiceDTE.Solution.Projects);
        }


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
            m_projects = new List<HierarchialData.Project>();
            if (projects == null)
                return;

            foreach (Project project in projects)
            {
                m_projects.Add(new HierarchialData.Project(project));
            }
            m_LighthouseControl.showProjects(m_projects);
        }
    }
}