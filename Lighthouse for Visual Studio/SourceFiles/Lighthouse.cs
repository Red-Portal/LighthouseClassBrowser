//------------------------------------------------------------------------------
// <copyright file="Lighthouse.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System.IO.Packaging;
using System.Runtime.CompilerServices;
using System.Windows;
using EnvDTE80;
using LighthouseClassBrowser.HierarchialData;
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
            this.Content = new LighthouseControl();
            m_LighthouseControl = (LighthouseControl) this.Content;
             
            m_ServiceDTE = serviceProvider.GetService(typeof(DTE)) as DTE;

            if (m_ServiceDTE != null)
                setEvents();

            if(m_ServiceDTE.Solution.IsOpen)
                setProjects(m_ServiceDTE.Solution.Projects);

            var interf = new LighthouseInterface();
        }

        private ProjectItemsEvents m_ProjectEvents;
        private SolutionEvents m_SolutionEvents;
        private WindowEvents m_WindowEvents;
        private static Package m_Package;
        private readonly DTE m_ServiceDTE;
        private LighthouseControl m_LighthouseControl;
        private List<HierarchialData.Project> m_projects { get; set; }

        public static readonly Type TypeOfProject = typeof(HierarchialData.Project);
        public static readonly Type TypeOfClass = typeof(HierarchialData.Class);
        public static readonly Type TypeOfMethod = typeof(HierarchialData.Method);
        public static readonly Type TypeOfVariable = typeof(HierarchialData.Variable);
        public static readonly Type TypeOfSourceFile = typeof(HierarchialData.SourceFile);

        /// <summary>
        /// Static method for setting ServiceProvider regardless of whether Lighthouse is instantiated or not.
        /// </summary>
        /// <param name="package"></param>
        public static void setPackage(Package package)
        {
            Lighthouse.m_Package = package;
        }

        ///

        private void setEvents()
        {
            m_SolutionEvents = ((Events2) m_ServiceDTE.Events).SolutionEvents;
            m_ProjectEvents = ((Events2) m_ServiceDTE.Events).ProjectItemsEvents;
            m_WindowEvents = ((Events2) m_ServiceDTE.Events).WindowEvents;
            m_SolutionEvents.Opened += eventOnSolutionOpen;
            m_SolutionEvents.AfterClosing += eventOnSolutionClosed;
            m_SolutionEvents.ProjectRenamed += eventOnProjectRename;
            m_SolutionEvents.ProjectAdded += eventOnProjectAdded;
            m_SolutionEvents.ProjectRemoved += eventOnProjectRemoved;
            m_ProjectEvents.ItemAdded += eventOnProjectItemAdded;
            m_ProjectEvents.ItemRemoved += eventOnProjectItemRemoved;
            m_ProjectEvents.ItemRenamed += eventOnProjectItemRenamed;
        }

        private IServiceProvider serviceProvider //external initialization of static variable ServiceProvider
        {
            get { return Lighthouse.m_Package; }
        }

        private void eventOnProjectItemAdded(ProjectItem item)
        {
            setProjects(m_ServiceDTE.Solution.Projects);
        }
        private void eventOnProjectItemRenamed(ProjectItem item, string name)
        {
            setProjects(m_ServiceDTE.Solution.Projects);
        }
        private void eventOnProjectItemRemoved(ProjectItem item)
        {
            setProjects(m_ServiceDTE.Solution.Projects);
        }
        private void eventOnSolutionOpen()
        {
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
        private void eventOnSolutionClosed()
        {
            setProjects(m_ServiceDTE.Solution.Projects);
        }

        internal static void eventSelectedCodeElement(HierarchialData.Item item)
        {
            if (item.GetType() == TypeOfClass)
            {
                var dataClass = item as HierarchialData.Class;
                moveToCodeElement(dataClass.m_CodeElement);
            }
            else if (item.GetType() == TypeOfMethod)
            {
                var method = item as HierarchialData.Method;
                if (method != null)
                    moveToCodeElement(method.m_CodeElement);
            }
            else if (item.GetType() == TypeOfVariable)
            {
                var variable = item as HierarchialData.Variable;
                if (variable != null)
                    moveToCodeElement(variable.m_CodeElement);
            }
        }

        internal static void moveToCodeElement(CodeElement codeElement)
        {
            if (codeElement.ProjectItem.Document == null)
                codeElement.ProjectItem.Open("{00000000-0000-0000-0000-000000000000}");

            codeElement.ProjectItem.Document.Activate();
            Window window = codeElement.ProjectItem.Document.ActiveWindow;

            TextSelection textSelection = window.Document.Selection as TextSelection;

            textSelection.MoveToPoint(codeElement.StartPoint);
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
        }
    }
}