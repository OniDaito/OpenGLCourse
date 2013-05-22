
    MMMMMMMMMMMM77$7777$ZZZZ777MMMMMMMMMMMMM
    MMMMMMMMMZZZ7777777777ZZZ77777MMMMMMMMMM
    MMMMMMM$77$ZZ77777777ZZZZZZZ7777MMMMMMMM
    MMMMMZ777ZZZZZZZZ77.ZZZZZZZZZZ7777MMMMMM
    MMMMZZZZZZZZZZZZZ,. ..ZZZZZZZZZZZZZMMMMM
    MMN7ZZ777ZZZZZZZ...   .ZZZZZZZ777ZZZDMMM
    MM777777777ZZZ..       =ZZZZZ777777ZZMMM
    M7$Z77777777Z.          .7Z77777777ZZZMM
    ZZZZ7777777..Z7.        . .$77777777ZZZM
    7ZZZZ7777..   ~7..I.    .   O.7777777Z7M
    7ZZZZZ77..      Z77... ........I77777$7M
    7ZZZZZ..       ZZ.      .      ..77ZZZ7$
    7ZZZZI.        ..  .  .Z.       .:ZZZZ77
    7ZZ7777.        .    IZ..      .7ZZZZZ7D
    7$7777777...        7.~O     .I777ZZZZ7M
    ZZZ77777777Z     .     .7Z. .777777ZZZ7M
    MZZI777777777+          ..$77777777ZZ7MM
    MDZZ7777777ZZZ7...      ..ZZ7777777I7ZMM
    MMOZZZ777$ZZZZZ...    . ZZZZZZ7777Z7$MMM
    MMMOZZZ7ZZZZZZZZ$  .. 7ZZZZZZZZ7ZZZZMMMM
    MMMMMZI7IZZZZZZZZZ,..$ZZZZZZZZZ77ZMMMMMM
    MMMMMM77777ZZZZZZZZ777777ZZZZ777ZMMMMMMM
    MMMMMMMM877777ZZZI777777777ZZZ$MMMMMMMMM
    MMMMMMMMMMM87777ZZZ777777$7ZMMMMMMMMMMMM
    MMMMMMMMMMMMMMMMDZZZZZ8MMMMMMMMMMMMMMMMM

                          __   _
      ___ ________ ____  / /  (_)______
     / _ `/ __/ _ `/ _ \/ _ \/ / __(_-<
     \_, /_/  \_,_/ .__/_//_/_/\__/___/
    /___/        /_/
       __            __
      / /  ___ _____/ /__ ___ ___  ___ ________
     / _ \/ _ `/ __/  '_/(_-</ _ \/ _ `/ __/ -_)
    /_//_/\_,_/\__/_/\_\/___/ .__/\_,_/\__/\__/
                           /_/


# An Introduction to OpenGL  - Part 1 - Your first triangle #


This short, half-day course is an introduction to OpenGL and graphics programming in general. This code covers the main examples we'd like to cover in the first section. Going from nothing, all the way to your first, spinning triangle. 


## Requirements ##

  * A laptop (on the day) or any machine capable of supporting OpenGL 3.2+
  * A good text editor such as Vim, Emacs, Sublime, Textmate, Notepad++ etc
  * [CMake](http://www.cmake.org/cmake/resources/software.html) for whatever platform
  * [Boost](http://www.boost.org/) for whatever platform you are on
  * Knowledge of C++ (basic level)
  * A lust for graphics fun!

The 5 parts are as follows:

  * Part1 - Context
  * Part2 - Shaders
  * Part3 - Buffers
  * Part4 - Display
  * Part5 - Matrices

This couse assumes a good knowledge of C++ and programming in whatever OS you tend to use. It is, however, not too heavy going and a lot of code is given to you. This couse will take you through creating a context, clearing a screen, preparing buffers and shaders, then combining them all together to create something on the screen.

## Installation ##

### Windows ###

You will need:

  * Visual Studio 2010 with Service Pack 1
  * CMake for Windows
  * Boost compiled for windows and installed (and in your path)

The most important thing is to download a copy of boost and get it built. You can do this by downloading the zip from the boost page, unzipping and then opening your *cmd* command line program, going to the new boost directory and typing the following:

    bjam toolset=msvc-10.0 threading=multi link=static runtime-link=static release install


When this completes run this command

    bjam toolset=msvc-10.0 threading=multi link=static runtime-link=static debug install

This will compile the Boost Libraries as static, so we can compile them into our final OpenGL library.

Once this is done, install CMake by going to their webpage and downloading the installer. CMake is a program for generating makefiles on many platforms. It is used by OpenCV, GLFW and many other libraries common in computer graphics and vision.

CMake has two bars at the top to fill in the path to the source code and the build path. In the top bar marked *Where is the source code* navigate to the OpenGLCourse directory. In the box marked *where to build the binaries* use the same directory but append */build* to the  path.

You can then hit the *configure* button. You will be asked to *specify the generator for this project*. Select *Visual Studio 10* and *use default native compilers*. You will now see the options appear in the main window. Press the *generate* buttton and your makefiles will be generated. 

If you now navigate to your *build* directory, you will see an OpenGLCourse project file for visual studio 10. You can now build the course in the normal manner.


### OSX ###

You will need:
  * CMake
  * XCode tools (or Clang at the very least)
  * Boost
  * terminal.app or iTerm.app

Under OSX, you still need cmake. Its best to use cmake from the command line. I use the wonderful program [HomeBrew](http://mxcl.github.io/homebrew/). This makes installing CMake and Boost a doddle. Under OSX, this course uses dynamic boost libraries compiled for x86_64. In addition, the programs are built as bundles (.app directories essentially) but the libraries are not copied across at present.

To build the main library, make a directory called *build*. Navigate inside this directory (in the terminal or iTerm app) and type the following command

    cmake ..

This will launch Cmake (if you have installed it) which creates the makefiles (most likely for Clang). Once this is done (hopefully with no errors) you can type

    make

This creates the all the necessary programs and libraries.


###Linux 64###

You will need :

  * CMake
  * GCC
  * Development libraries for gtkmm-3.0, opengl and xxf86vm
  * Boost Shared libs installed

Under linux, we build our library as a shared object with dynamic linking to the various libraries we need. Off the top of my head I cant remember them all but OpenGL, gtkmm and xxf86vm are definitely needed, along with the boost shared libraries.

Under ubuntu, one can apt-get the required libraries easily enough if you find you are missing them. I have not tested under other distributions however.

Once installed, navigate to the project directory and create a directory called *build*. Move inside this directory and type:

    cmake ..

This will launch cmake and create the makefiles you need. After that type:

    make

And hopefully, all the examples and libraries will build.

I havent had chance to make a 32 bit version of this. In order to do so, one needs to download and build AntTweakBar and GLFW for 32 bit shared libs.




## Thanks ##

  * The London Hackspace - http://london.hackspace.org.uk
  * The GLFW Team
  * The GLM Team
  * The GLEW Team
  * The people who come to the Graphics Hackspace


## Resources ##

  * [http://www.glfw.org/](http://www.glfw.org/)
  * [http://glm.g-truc.net/](http://glm.g-truc.net/)
  * [http://glew.sourceforge.net/](http://glew.sourceforge.net/)


## Books ##
 
The Orange Book
The Red Book

... will add more!

## Contacts ##

Ben Blundell - oni@graphicshackspace.org | ben@section9.co.uk
