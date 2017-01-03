//------------------------------------------------------------------------------
// <copyright file="LighthouseControl.xaml.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Reflection;
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

        internal void showClasses()
        {
            var items = new List<HierarchialData.Item>();

            foreach (HierarchialData.SourceFile file in m_SelectedSourceFiles)
                items.AddRange(file.m_Classes);


            ListBoxClassBrowser.DataContext = items;
        }

        internal void showMethods(HierarchialData.Class dataClass)
        {
            var list = new List<HierarchialData.Method>();

            foreach (HierarchialData.Method method in dataClass.m_Methods)
            {
                list.Add(method);
            }

            ListBoxMethodBrowser.DataContext = list;
        }

        internal void showVariables(HierarchialData.Class dataClass)
        {
            var list = new List<HierarchialData.Variable>();

            foreach (HierarchialData.Variable variable in dataClass.m_Variable)
            {
                list.Add(variable);
            }

            ListBoxVariableBrowser.DataContext = list;
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
                    if (item.GetType() == LighthouseClassBrowser.Lighthouse.TypeOfProject)
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
                    if (item.GetType() == LighthouseClassBrowser.Lighthouse.TypeOfProject)
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
                    if (item.GetType() == LighthouseClassBrowser.Lighthouse.TypeOfProject)
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
                    if (item.GetType() == LighthouseClassBrowser.Lighthouse.TypeOfSourceFile)
                        list.Add(item as HierarchialData.SourceFile);
                }

                m_SelectedSourceFiles = list;
                showClasses();
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

        private void ListBoxClassBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            foreach (HierarchialData.Class dataClass in ListBoxClassBrowser.SelectedItems)
            {
                m_Lighthouse.eventSelectedCodeElement(dataClass);

                showMethods(dataClass);
                if (ButtonMethodAbstract.IsChecked == true)
                    eventGernericAbstractBrowser<HierarchialData.Method>(ListBoxMethodBrowser);

                showVariables(dataClass);
                if (ButtonVariableAbstract.IsChecked == true)
                    eventGernericAbstractBrowser<HierarchialData.Variable>(ListBoxVariableBrowser);
            }
        }

        private void ListBoxMethodBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            foreach (HierarchialData.Method method in e.AddedItems)
            {
                m_Lighthouse.eventSelectedCodeElement(method);
            }
        }

        private void ListBoxVariableBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            foreach (HierarchialData.Variable variable in e.AddedItems)
            {
                m_Lighthouse.eventSelectedCodeElement(variable);
            }
        }

        private void ButtonClassAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonClassAbstract.IsChecked == true)
                eventGernericAbstractBrowser<HierarchialData.Class>(ListBoxClassBrowser);
            else
            {
                showClasses();
            }
        }

        private void ButtonClassDerived_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonClassStatic_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonMethodAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonMethodAbstract.IsChecked == true)
                eventGernericAbstractBrowser<HierarchialData.Method>(ListBoxMethodBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showMethods(item as HierarchialData.Class);
            }
        }

        private void ButtonMethodDerived_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonMehtodStatic_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonVariableAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonVariableAbstract.IsChecked == true)
                eventGernericAbstractBrowser<HierarchialData.Variable>(ListBoxVariableBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showVariables(item as HierarchialData.Class);
            }
        }

        private void ButtonVariableDerived_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonVariableStatic_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void eventGernericAbstractBrowser<T>(ListBox browser)
        {
            var list = new List<T>();

            foreach (HierarchialData.Item item in browser.Items)
            {
                HierarchialData.Element element = item as HierarchialData.Element;

                if (isAbstract(element.m_CodeElement))
                    list.Add((T) Convert.ChangeType(element, typeof(T)));
            }
            browser.DataContext = list;
        }

        private bool isAbstract(CodeElement element)
        {
            if (element.Kind == vsCMElement.vsCMElementClass)
            {
                vsCMAccess accessElement = (element as CodeClass).Access;
                return isAccessable(accessElement);
            }
            else if (element.Kind == vsCMElement.vsCMElementFunction)
            {
                vsCMAccess accessElement = (element as CodeFunction).Access;
                return isAccessable(accessElement);
            }
            else if (element.Kind == vsCMElement.vsCMElementVariable)
            {
                vsCMAccess accessElement = (element as CodeVariable).Access;
                return isAccessable(accessElement);
            }
            else if(element.Kind == vsCMElement.vsCMElementProperty)
            {
                vsCMAccess accessElement = (element as CodeProperty).Access;
                return isAccessable(accessElement);
            }

            return false;
        }

        private bool isAccessable(vsCMAccess accessLevel)
        {
            return accessLevel == vsCMAccess.vsCMAccessPublic
                   || accessLevel == vsCMAccess.vsCMAccessDefault;
        }
    }
}