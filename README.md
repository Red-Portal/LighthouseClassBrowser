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

1. `Make` or `build` the project
2.  In the main menu, select `Build (Prepare) Plugin Module for Deployment`.
3. A `.jar` or `.zip` file will be created
4. copy the file to `.IntelliJIDEAx0\config\plugins` folder. Restart the IDE
5. In the main menu, select `File | Setting` to open `Settings` dialog box.
6. In the `Settings` dialog box, Under `IDE Settings` click `Plugin`.
7. In plugins area open the `Installed` tab, and then and then select the check-box next to the plugin name.
8. click OK and restart the IDE.
9. Open Lighthouse in, View ->  Tool Window -> Lighthouse.

![UsingIntelliJExample](https://github.com/Red-Portal/LighthouseClassBrowser/blob/master/ExampleOpeningIntelliJ.gif)

## Current Version Info
* The `Derived` feature for the variables, method browser is yet to be implemented
* In the Visual Studio version only C# is currently supported.

## Upcoming Features
* Asyncronous Data Collection
* C#, Visual Studio implementation
* Java, IntelliJ implementation

## Dependencies
* [Swig](https://github.com/swig/swig), GPLv3
* [Protobuf](https://github.com/google/protobuf), custom license
* [gtest](https://github.com/google/googletest/tree/master/googletest), custom license


	LighthouseClassBrowser, a smalltalk Class Browser style plugin module
    Copyright (C) 2017  Red-Portal, jzi040941


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.