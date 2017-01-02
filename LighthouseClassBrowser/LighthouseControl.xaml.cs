//------------------------------------------------------------------------------
// <copyright file="LighthouseControl.xaml.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Windows.Data;
using System.Windows.Forms.VisualStyles;
using EnvDTE;
using LighthouseClassBrowser.HierarchialData;
using Microsoft.Internal.VisualStudio.Shell;
using Project = LighthouseClassBrowser.HierarchialData.Project;

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
            ListBoxProjectBrowser.SelectionMode = SelectionMode.Multiple;
            ListBoxClassBrowser.SelectionMode = SelectionMode.Single;
            ListBoxMethodBrowser.SelectionMode = SelectionMode.Single;
            ListBoxVariableBrowser.SelectionMode = SelectionMode.Single;
        }

        private Lighthouse m_Lighthouse;
        private static readonly Type TypeOfProject = typeof(HierarchialData.Project);
        private static Type TypeOfClass = typeof(HierarchialData.Class);
        private static Type TypeOfMethod = typeof(HierarchialData.Method);
        private static Type TypeOfVariable = typeof(HierarchialData.Variable);
        private static readonly Type TypeOfSourceFile = typeof(HierarchialData.SourceFile);

        private List<HierarchialData.SourceFile> m_SelectedSourceFiles;

        internal void showProjects(List<HierarchialData.Project> projects)
        {
            var items = new List<HierarchialData.Item>();
            foreach (HierarchialData.Project project in projects)
            {
                items.Add(project);

                foreach (HierarchialData.SourceFile file in project.m_SourceFile)
                {
                    items.Add(file);
                }
            }
            this.ListBoxProjectBrowser.DataContext = items;
        }
/*
        internal void showAddClasses(HierarchialData.SourceFile file)
        {
            var items = new List<HierarchialData.Item>();

            items.AddRange(file.m_Classes);

            if (ListBoxClassBrowser.DataContext == null)
                this.ListBoxClassBrowser.DataContext = new List<HierarchialData.Item>(items);
            else
                this.ListBoxClassBrowser.Items.Add(items);
        }

        internal void showRemoveClasses(HierarchialData.SourceFile file)
        {
            ListBoxClassBrowser.Items.Remove(file.m_Classes);
        }
        */

        internal void showClasses()
        {
            var items = new List<HierarchialData.Item>();

            foreach (HierarchialData.SourceFile file in m_SelectedSourceFiles)
                items.AddRange(file.m_Classes);
            

            ListBoxClassBrowser.DataContext = items;
        }



        internal void showMethods()
        {
            
        }

        internal void getVariables()
        {
            
        }

        private void ListBoxProjectBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            bool wasModified = false; //optimization flag



            // This loop is for checking if a recently removed sourceFile belongs to a already checked Project
            // if It is the case, the checked Project should be unchecked
            if (e.RemovedItems.Count > 0)
            {
                // this loop is for checking if the removed item is a project or not
                // if it is a project, then if the items of the project are all selected, they get
                // unselected at once.
                foreach (HierarchialData.Item item in e.RemovedItems)
                {
                    if (item.GetType() == TypeOfProject)
                    {
                        var project = item as HierarchialData.Project;
                        if (areAllItemsSelected(item as HierarchialData.Project))
                        {
                            selectPropertiesOfProject(item, false);
                            wasModified = true;
                        }
                    }
                }

                // If a recently removed item was a property of a previously selected project,
                // then since not all properties of the project are selected,
                // the project should be unseleted.
                HierarchialData.Item flaggedItem = null;
                foreach (HierarchialData.Item item in ListBoxProjectBrowser.SelectedItems)
                {
                    if (item.GetType() == TypeOfProject)
                    {
                        if (!areAllItemsSelected(item as HierarchialData.Project))
                        {
                            flaggedItem = item;
                        }
                    }
                }
                if (flaggedItem != null)
                {
                    ListBoxProjectBrowser.SelectedItems.Remove(flaggedItem);
                    wasModified = true;
                }
            }
            else if (e.AddedItems.Count > 0)
            {
                // loop for checking if a recently added item is a project type.
                // in this case, all the sourcefile corresponding to the project should be selected
                foreach (HierarchialData.Item item in e.AddedItems)
                {
                    if (item.GetType() == TypeOfProject)
                    {
                        selectPropertiesOfProject(item as HierarchialData.Project, true);
                        wasModified = true;
                    }
                }
            }

            if (!wasModified)
            {
                var list = new List<HierarchialData.SourceFile>();
                foreach (HierarchialData.Item item in ListBoxProjectBrowser.SelectedItems)
                {
                    if (item.GetType() == TypeOfSourceFile)
                        list.Add(item as HierarchialData.SourceFile);
                }
                if (list.Count != 0)
                {
                    m_SelectedSourceFiles = list;

                    showClasses();
                }
            }
        }

        private bool areAllItemsSelected(HierarchialData.Project project)
        {
            foreach (HierarchialData.SourceFile file in project.m_SourceFile)
            {
                if (!m_SelectedSourceFiles.Contains(file))
                    return false;
            }
            return true;
        }

        private void selectPropertiesOfProject(HierarchialData.Item item, bool isAdd)
        {
            var project = item as HierarchialData.Project;
            if (isAdd)
            {
                foreach (HierarchialData.SourceFile file in project.m_SourceFile)
                {
                    if (!ListBoxProjectBrowser.SelectedItems.Contains(file))
                        ListBoxProjectBrowser.SelectedItems.Add(file);
                }
            }
            else
            {
                foreach (HierarchialData.SourceFile file in project.m_SourceFile)
                    ListBoxProjectBrowser.SelectedItems.Remove(file);
            }
        }
    }
}