# Lighthouse Class Browser

A [Pharo Smalltalk] (http://pharo.org/) Nautilus System Browser style class browser for various IDEs.


- [Lighthouse Class Browser](#lighthouse-class-browser)
	- [Currently Supported IDE List](#currently-supported-ide-list)
	- [Features](#features)
		- [Code Navigation](#code-navigation)
		- [Hide Abstract Elements](#hide-abstract-elements)
		- [Show Parent of Derived Class](#show-parent-of-derived-class)
        - [Mark Static Elements](#mark-static-elements)
	- [Using Lighthouse in Microsoft Visual Studio](#using-lighthouse-in-microsoft-visual-studio)
        - [Installation](#installation)
	- [Using Lighthouse in Jetbrains IntelliJ IDEA](#using-lighthouse-in-jetbrains-intellij-idea)
		- [Installation](#installation)
    - [Version Info](#version-info)
    - [Upcoming Features](#upcoming-features)


## Currently Supported IDE List

* `Visual Studio 2015`
* `IntelliJ IDEA (ver 2016.2.5)`

## Features

![ExampleImage](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleImage.jpg)

Lighthouse always shows you the the classes of the selected project items.
It also shows you member methods, variables and properties of the selected class.

### Code Navigation

![CodeNavigation](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleNavigation.gif)

By selecting any of the Class, Method, Properties displayed, you can directly move to its position.

### Hide Abstract Elements

![HideAbstractMembers](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleAbstraction.gif)

By pressing `Abstract` button, encapsulated classes, methods, variables and properties are hidden from the browser.
Using this button you can directly check the encapsualation structure of your code.

### Show Parent of Derived Class

![ShowDerivedParent](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleDerived.gif)

Pressing the `Derived` button shows the parent class of the currently selected class in a different color.

### Mark Static Elements

![MarkStatic](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleStatic.gif)

The `Static` button marks static elements with a different color so you can identify them easily.

## Using Lighthouse in Microsoft Visual Studio
### Installation

1. Build the VSIX project in Visual Studio
2. Install Visual Studio Extension by executing "Project Folder"\bin\"Debug or Release"\LighthouseClassBrowser.vsix
3. Open Lighthouse in Visual Studio -> Tools -> Lighthouse

![UsingExample](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleOpening.gif)


## Using Lighthouse in Jetbrains IntelliJ IDEA 
### Installation

![UsingIntelliJExample](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleOpeningIntelliJ.gif)

## Current Version Info
* The `Derived` feature for the variables, method browser is yet to be implemented
* In the Visual Studio version only C# is currently supported.

## Upcoming Features
* Full C# implementation
* Support for Vim
* Support for C++ in Vim