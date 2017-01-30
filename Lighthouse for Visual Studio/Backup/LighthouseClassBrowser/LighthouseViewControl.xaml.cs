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
        internal LighthouseControl()
        {
            this.InitializeComponent();
            ListBoxProjectBrowser.SelectionMode = SelectionMode.Multiple;
            ListBoxClassBrowser.SelectionMode = SelectionMode.Single;
            ListBoxMethodBrowser.SelectionMode = SelectionMode.Single;
            ListBoxVariableBrowser.SelectionMode = SelectionMode.Single;

            m_VariableBrowserModel = new VariableBrowserModel(this);
            m_MethodBrowserModel = new MethodBrowserModel(this);
            m_ClassBrowserModel = new ClassBrowserModel(this, m_MethodBrowserModel, m_VariableBrowserModel);
            m_ProjectBrowserModel = new ProjectBrowserModel(this, m_ClassBrowserModel);
        }

        private ClassBrowserModel m_ClassBrowserModel;
        private ProjectBrowserModel m_ProjectBrowserModel;
        private MethodBrowserModel m_MethodBrowserModel;
        private VariableBrowserModel m_VariableBrowserModel;

        internal void showProjects(List<HierarchialData.Project> projects)
        {
            m_ProjectBrowserModel.eventProjectChanged(projects);
        }

        private void ListBoxProjectBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            bool wasModified = false; //optimization flag

            ButtonClassDerived.IsChecked = false;

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
                var list = new List<HierarchialData.Item>();
                foreach(HierarchialData.Item item in ListBoxProjectBrowser.SelectedItems)
                    list.Add(item);

                m_ProjectBrowserModel.eventSelectionChanged(list);
            }
        }

        private bool areAllItemsSelected(HierarchialData.Project project)
        {
            foreach (HierarchialData.SourceFile file in project.m_SourceFile)
            {
                if (!m_ProjectBrowserModel.m_SelectedItems.Contains(file))
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
            var list = new List<HierarchialData.Item>();
            foreach(HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                list.Add(item);

            m_ClassBrowserModel.eventClassSelectionChanged(list);

            foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                LighthouseClassBrowser.Lighthouse.eventSelectedCodeElement(item);
        }

        private void ListBoxMethodBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            foreach (HierarchialData.Item item in ListBoxMethodBrowser.SelectedItems)
                LighthouseClassBrowser.Lighthouse.eventSelectedCodeElement(item);
        }

        private void ListBoxVariableBrowser_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            foreach (HierarchialData.Item item in ListBoxVariableBrowser.SelectedItems)
                LighthouseClassBrowser.Lighthouse.eventSelectedCodeElement(item);
        }

        private void ButtonClassAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            m_ClassBrowserModel.eventButtonAbstractPressed();
        }

        private void ButtonClassDerived_OnClick(object sender, RoutedEventArgs e)
        {
            /*if (ButtonClassDerived.IsChecked == true)
            {
                var list = ListBoxClassBrowser.DataContext as List<HierarchialData.Item>;
                var collection = new List<HierarchialData.Class>();
                foreach (HierarchialData.Class selectedClass in ListBoxClassBrowser.SelectedItems)
                {
                    var index = list.IndexOf(selectedClass);

                    if (selectedClass.m_CodeElement.Kind == vsCMElement.vsCMElementClass)
                    {
                        foreach (CodeElement baseElement in (selectedClass.m_CodeElement as EnvDTE80.CodeClass2).Bases)
                        {
                            if (baseElement.FullName == "System.Object")
                                return;

                            var newElement = new HierarchialData.Class(baseElement);
                            list.Insert(index, newElement);
                            collection.Add(newElement);
                        }
                    }
                    else if (selectedClass.m_CodeElement.Kind == vsCMElement.vsCMElementInterface)
                    {
                        foreach (
                            CodeElement baseElement in (selectedClass.m_CodeElement as EnvDTE80.CodeInterface2).Bases)
                        {
                            if (baseElement.FullName == "System.Object")
                                return;

                            var newElement = new HierarchialData.Class(baseElement);
                            list.Insert(index, newElement);
                            collection.Add(newElement);
                        }
                    }
                }
                ListBoxClassBrowser.DataContext = new List<HierarchialData.Item>(list);
                ListBoxProjectBrowser.UpdateLayout();
                changeListBoxItemColorGeneric(ListBoxClassBrowser, collection);
            }
            else
                showClasses();*/
        }

        private void ButtonClassStatic_OnClick(object sender, RoutedEventArgs e)
        {
            /*if (ButtonClassStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxClassBrowser);
            else
                showClasses();*/
        }

        private void ButtonMethodAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            m_MethodBrowserModel.eventButtonAbstractPressed();

            /*if (ButtonMethodAbstract.IsChecked == true)
                eventGenericAbstractBrowser<HierarchialData.Method>(ListBoxMethodBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showMethods(item as HierarchialData.Class);
            }

            if(ButtonMethodStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxMethodBrowser);*/
        }

        private void ButtonMethodDerived_OnClick(object sender, RoutedEventArgs e)
        {

        }

        private void ButtonMethodStatic_OnClick(object sender, RoutedEventArgs e)
        {
           /* if (ButtonMethodStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxMethodBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showMethods(item as HierarchialData.Class);
            }*/
        }

        private void ButtonVariableAbstract_OnClick(object sender, RoutedEventArgs e)
        {
            m_VariableBrowserModel.eventButtonAbstractPressed();

            /*if (ButtonVariableAbstract.IsChecked == true)
                eventGenericAbstractBrowser<HierarchialData.Variable>(ListBoxVariableBrowser);
            else
            {
                foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
                    showVariables(item as HierarchialData.Class);
            }

            if(ButtonVariableStatic.IsChecked == true)
                eventGenericIsStatic(ListBoxVariableBrowser);*/
        }

        private void ButtonVariableDerived_OnClick(object sender, RoutedEventArgs e)
        {
        }

        private void ButtonVariableStatic_OnClick(object sender, RoutedEventArgs e)
        {
            //if (ButtonVariableStatic.IsChecked == true)
            //    eventGenericIsStatic(ListBoxVariableBrowser);
            //else
            //{
            //    foreach (HierarchialData.Item item in ListBoxClassBrowser.SelectedItems)
            //        showVariables(item as HierarchialData.Class);
            //}
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

        private void changeListBoxItemColorGeneric<T>(ListBox browser, List<T> elements)
        {
            foreach (T element in elements)
            {
                browser.UpdateLayout();
                browser.ScrollIntoView((object)element);
                var item = browser.ItemContainerGenerator.ContainerFromItem((object) element) as ListBoxItem;
                item.Background = new SolidColorBrush(Colors.Tomato);
            }
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
            if (element.Kind == vsCMElement.vsCMElementInterface)
            {
                var codeTwoType = element as EnvDTE80.CodeInterface2;

                if (typeof(T) == typeof(vsCMAccess))
                    return (T) Convert.ChangeType(codeTwoType, typeof(T));
                else if (typeof(T) == typeof(bool))
                    return (T) Convert.ChangeType(codeTwoType, typeof(T));
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
    }
}