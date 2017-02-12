# Implementation Guidelines
These are guidlines on implementing lighthouse on your environment.
Some of these guidlines are supposed to define what is 'Lighthouse'.
Other guidlines are just to help you easily make your version.

## Essentials Rules
In order for a plugin to be called a ```Lighthouse Class Browser```,
the plugin must follow these descriptions. However it's really up to you.
We just hope you follow these descriptions.

1. There should be four listboxes which are called browsers.
2. From the far left, the first browser should...
    * Show the elements just above the classes on the language hierarchy.
    * Multiple of these elements should be selectable at once.
3. The second browser should...
    * Show the classes contained within the selected first browser's elements.
    * Only one class should be selectable at once.
    * Interfaces, abstract classes are all considered as classes.
4. The third browser should...
    * Show the methods contained within the selected second browser's elements.
5. The fourth browser should...
    * Show the properties contained within the selected second browser's elements.
    * By property, it means member variables, member instances.
    * In case of languages with higher-order functions, we suggest these are treated as methods.
6. All the content of the browsers must reflect the real time changes in the user's project.
7. The buttons if not all, must be implemented.
    * What the buttons do, is up to you. Below are suggestions.

## Suggestions
These are suggestions. These are not must-follow rules. These suggestions should
help you easily implement your own version, or raise the quality of the implementation.

1. Use swig. It will help you live longer. We even provided you the interface file for that.
2. Updating the elements(extracting information from the user's project) should be done asynchronously.
    * The extracting process should be done in an independent thread.
    * This should stop the UI thread from losing responsiveness.
3. These are the functionalities we suggest for implementing the buttons.
    * Abstract : This button hides abstracted data (private methods, private properties).
    * Static : This button only shows static elements (static methods, static properties).