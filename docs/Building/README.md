# Building Lighthouse
Lighthouse main module is a C++ shared library.

## Dependencies
Because Ligthouse depends on the open-source projects as below,

- [gtest](https://github.com/google/googletest)
- [protobuf](https://github.com/google/protobuf)
- [swig](https://github.com/swig/swig)

You must build these project locally.
gtest ___can be ommited__ if you do not need tests.

### Protobuf
Lighthouse used protobuf for communicating across platforms.
In order to use lighthouse, you need to generate Protobuf source files
of your target language.

And Lighthouse main module depends on protobuf static libraries.

After building protobuf,
```
1. build protobuf
2. link the static libraries.
3. add the include headers to your include path
4. keep the protoc executable for later.
```

### gtest
Protobuf's tests are implemented using google's test framework gtest.
In order to implement your own tests or use the already implemented tests,

```
1. Build gtest
2. link the static libraries
3. add the include headers to your include path
```

### swig
In order to use Lighthouse main module in other languages, We strictly recommend swig.
If you can do all the work on your own, never mind swig.

If not, then you can build swig or download a prebuild binary at the [official page](www.swig.org).

Using the swig executable, C++ and target language wrappers are generated.
__You must include the C++ wrapper when building Ligthhouse main module__

```
1. build swig (or download the official prebuilt binary)
```


## Building Lighthouse
After you included all the dependencies,

Compile lighthouse using swig.
First find the directives to your target language.

```
-allegrocl            Generate ALLEGROCL wrappers  
-chicken              Generate CHICKEN wrappers  
-clisp                Generate CLISP wrappers  
-cffi                 Generate CFFI wrappers  
-csharp               Generate C# wrappers  
-d                    Generate D wrappers  
-go                   Generate Go wrappers  
-guile                Generate Guile wrappers  
-java                 Generate Java wrappers  
-javascript           Generate Javascript wrappers  
-lua                  Generate Lua wrappers  
-modula3              Generate Modula 3 wrappers  
-mzscheme             Generate Mzscheme wrappers  
-ocaml                Generate Ocaml wrappers  
-octave               Generate Octave wrappers  
-perl                 Generate Perl wrappers  
-php5                 Generate PHP5 wrappers  
-php7                 Generate PHP7 wrappers  
-pike                 Generate Pike wrappers  
-python               Generate Python wrappers  
-r                    Generate R (aka GNU S) wrappers  
-ruby                 Generate Ruby wrappers  
-scilab               Generate Scilab wrappers  
-sexp                 Generate Lisp S-Expressions wrappers  
-tcl                  Generate Tcl wrappers  
-uffi                 Generate Common Lisp / UFFI wrappers  
-xml                  Generate XML wrappers  
```

add swig to your computers ```PATH```.  
Entering the commands below will generate source files.

```
cd {path-to}/LighthouseClassBrowser/Lighthouse/

swig -{target-language-directive} -c++ -outdir Swig Swig/LighthouseInterface.i
```

add ```LighthouseInterface_wrap.cxx``` to your project.  
Build the project.

__check if the ```__TEST__``` macro directive in, ```Headers/LighthouseHeader.h``` is unefined or commented.__

The resulting dll file is the successfully built Lighthouse main module.