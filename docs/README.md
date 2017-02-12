# Documentation

## Documents
- [how to build this project](Building/README.md)
- [Tutorial on how to make your lighthouse implementation](/Tutorial)
- [Guidelines on implementing lighthouse](/GuideLines)
- [A tour on the Visual Studio implementation](/Implementation)

## Basics
Lighthouse is a C++ shared library that with the help of swig,
you can port to many different platforms.

Lighthouse uses protobuf to communicate across platforms.
And it uses swig for cross platform use of the C++ shared library.
The Lighthouse C++ module should make building a Lighthouse plugin implementation much easier.

first, you must build the shared library.
Follow [this guide](/Building).

Then using the library and swig,
You should implement the rest on your environment.
Follow [this guide](/Tutorial)

Lighthouse suggests following [these guidelines](/GuideLines) on the implementation.
However these are just suggestions, Ligthhouse is basically implementation defined.
Do what you want! ([don't forget to buy the beer!](../BEERWARE-LICENSE))

There is a guide on how the Visual Studio implementation was done.
Reference [this](/Implementation) if you need to get ideas.