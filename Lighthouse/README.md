# WHAT IS WHAT CONTAINING WHAT
### This Readme explains you what folder contains what that does what

## Headers
This folder contains the headers for the project.
In case the ```__TEST__``` directive is defined,
The ```TestHeader.h``` will not be included.

## Source
This folder contains the source files for the project

## protobuf
This folder contains the files related to [protobuf](https://github.com/google/protobuf).
```.proto``` file is the protobuf message script file.
Compiling it through protobuf will result in protobuf source files of the your target language.

precompiled C++ protobuf source files are included as default.
These should be included in the project in order to compile the C++ module.

## swig
This folder contains the swig interface script file.
In order to use the C++ module, you must generate a C++ wrapper, and target language wrapper
using swig.
Further informations on using swig for this project are in [docs](../docs)

## Submodules
These are the dependencies of the project.
If you do not intend to test the C++ module, you don't need gtest.

## Tests
This folder contains files related to testing the C++ module.
```TestMain.cpp``` is the source file containing the main function.
In order to use [gtest](https://github.com/goolge/googletest) you must have a main function.

```Test.cpp``` contains all the tests.