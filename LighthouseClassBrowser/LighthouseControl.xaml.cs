//------------------------------------------------------------------------------
// <copyright file="LighthouseControl.xaml.cs" company="Company">
//     Copyright (c) Company.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Windows.Media;
using EnvDTE;
using EnvDTE80;
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
                    {
                        var sourceFile = item as HierarchialData.SourceFile;
                        sourceFile.setClassesRecursive(sourceFile.m_ProjectItem.FileCodeModel.CodeElements);
                        list.Add(sourceFile);
                    }
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
                dataClass.setClassComponents(dataClass.m_CodeElement);

                m_Lighthouse.eventSelectedCodeElement(dataClass);

                showMethods(dataClass);
                if (ButtonMethodAbstract.IsChecked == true)
                    eventGenericAbstractBrowser<HierarchialData.Method>(ListBoxMethodBrowser);
                if(ButtonMethodStatic.IsChecked == true)
                    eventGenericIsStatic(ListBoxMethodBrowser);

                showVariables(dataClass);
                if (ButtonVariableAbstract.IsChecked == true)
                    eventGenericAbstractBrowser<HierarchialData.Variable>(ListBoxVariableBrowser);
                if(ButtonVariableStatic.IsChecked == true)
                    eventGenericIsStatic(ListBoxVariableBrowser);
            }
        }

        private void ListBoxMethodBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            foreach (HierarchialData.Method method in e.AddedItems)
                m_Lighthouse.eventSelectedCodeElement(method);
        }

        private void ListBoxVariableBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            foreach (HierarchialData.Variable variable in e.AddedItems)
                m_Lighthouse.eventSelectedCodeElement(variable);
        }

        private void ButtonClassAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonClassAbstract.IsChecked == true)
                eventGenericAbstractBrowser<HierarchialData.Class>(ListBoxClassBrowser);
            else
                showClasses();

            if (ButtonClassStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxClassBrowser);
        }

        private void ButtonClassDerived_OnClick(object sender, RoutedEventArgs e)
        {
            
        }

        private void ButtonClassStatic_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonClassStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxClassBrowser);
            else
                showClasses();
        }

        private void ButtonMethodAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonMethodAbstract.IsChecked == true)
                eventGenericAbstractBrowser<HierarchialData.Method>(ListBoxMethodBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showMethods(item as HierarchialData.Class);
            }

            if(ButtonMethodStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxMethodBrowser);
        }

        private void ButtonMethodDerived_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonMethodStatic_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonMethodStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxMethodBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showMethods(item as HierarchialData.Class);
            }
        }

        private void ButtonVariableAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonVariableAbstract.IsChecked == true)
                eventGenericAbstractBrowser<HierarchialData.Variable>(ListBoxVariableBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showVariables(item as HierarchialData.Class);
            }

            if(ButtonVariableStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxVariableBrowser);
        }

        private void ButtonVariableDerived_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonVariableStatic_OnClick(object sender, RoutedEventArgs e)
        {
            if (ButtonVariableStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxVariableBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showVariables(item as HierarchialData.Class);
            }
        }

        private void eventGenericIsStatic(ListBox browser)
        {
            foreach (HierarchialData.Element element in browser.Items)
            {
                if (getClassTwoProperties<bool>(element.m_CodeElement))
                {
                    browser.UpdateLayout();
                    var item = browser.ItemContainerGenerator.ContainerFromItem((object)element) as ListBoxItem;
                    item.Background = new SolidColorBrush(Colors.LightBlue);
                }
            }
        }

        private void eventGenericAbstractBrowser<T>(ListBox browser)
        {
            var list = new List<T>();

            foreach (HierarchialData.Item item in browser.Items)
            {
                HierarchialData.Element element = item as HierarchialData.Element;

                if (isAbstract(getClassTwoProperties<vsCMAccess>(element.m_CodeElement))) 
                    list.Add((T) Convert.ChangeType(element, typeof(T)));
            }
            browser.DataContext = list;
        }

        private T getClassTwoProperties<T>(CodeElement element)
        {
            if (element.Kind == vsCMElement.vsCMElementClass)
            {
                var codeTwoType = element as EnvDTE80.CodeClass2;

                if (typeof(T) == typeof(vsCMAccess))
                    return (T)Convert.ChangeType(codeTwoType.Access, typeof(T));
                else if (typeof(T) == typeof(bool))
                    return (T)Convert.ChangeType(codeTwoType.IsShared, typeof(T));
            }
            else if (element.Kind == vsCMElement.vsCMElementFunction)
            {
                var codeTwoType = element as EnvDTE80.CodeFunction2;

                if (typeof(T) == typeof(vsCMAccess))
                    return (T) Convert.ChangeType(codeTwoType.Access, typeof(T));
                else if (typeof(T) == typeof(bool))
                    return (T) Convert.ChangeType(codeTwoType.IsShared, typeof(T));
            }
            else if (element.Kind == vsCMElement.vsCMElementVariable)
            {
                var codeTwoType = element as EnvDTE80.CodeVariable2;

                if (typeof(T) == typeof(vsCMAccess))
                    return (T) Convert.ChangeType(codeTwoType.Access, typeof(T));
                else if (typeof(T) == typeof(bool))
                    return (T) Convert.ChangeType(codeTwoType.IsShared, typeof(T));
            }
            else if (element.Kind == vsCMElement.vsCMElementProperty)
            {
                var codeTwoType = element as EnvDTE80.CodeProperty2;

                if (typeof(T) == typeof(vsCMAccess))
                    return (T) Convert.ChangeType(codeTwoType.Access, typeof(T));
                else if (typeof(T) == typeof(bool))
                    return (T) Convert.ChangeType(codeTwoType.IsShared, typeof(T));
            }
            return (T) Convert.ChangeType(null, typeof(T));
        }

        private bool isAbstract(vsCMAccess accessLevel)
        {
            return accessLevel == vsCMAccess.vsCMAccessPublic
                   || accessLevel == vsCMAccess.vsCMAccessDefault;
        }
    }
}