# GUI Application to automatically copy a file to multiple locations once changed

This is a beginner project.

## Usage

It's pretty self explanatory, but in case you need clarification:

- You can add files to be watched for changes by pressing 'Add file to be watched'

- You can add file paths to copy the watched file to by selecting it in the tree view and clicking 'Add copy of [watched file name] to be saved'. You can remove those file paths by selecting them and clicking 'Remove [file path]'. Note that this will not delete the file from the file system.

- You can also remove the files to be watched by clicking them and selecting 'Remove [watched file name]'.


## Dev Build configuration
If you want to build without the Qt library's make tools, ie for development from Eclipse, you may need to configure some paths and copy some files in order to build this project. These are the paths you may need to configure:
- Under Project > Properties > C/C++ Build > Settings, under the Tool Settings menu:
	- C++ Compiler > Includes in the include paths (-I) box: /usr/include/x86_64-linux-gnu/qt5/. This should point at the Qt5 include directory. 
	- C++ Linker > Libraries in the Library search path (-L) box: /usr/lib/x86_64-linux-gnu/. This should point at the Qt5 lib directory.
- In src/meta.sh you may need to change moc to the absolute path of the Qt5 moc executable (located in the Qt5 bin directory or under /usr/lib/qt5/bin/ in Linux systems).

On Windows under msys2, depending on how you run the executable, you may need to copy some .dll files from the mingw64/bin directory to the location of the executable. If you run the executable from Explorer it usually pops up an error message that says which DLLs are missing.

## Development notes
*You may need to modify some project settings to be able to compile from Eclpise. See [Build configuration](#build-configuration)*.

This project was created with [Eclipse CDT](https://projects.eclipse.org/projects/tools.cdt). In order to open it for development, you need to install this IDE (you need to install the Eclipse IDE and then add the CDT components to it). When everything is installed, you can select 'Open projects from file system' and choose the cloned directory. When it is opened, go to Project > Build Configurations > Set Active to set the desired target if you want to build from within Eclipse. Then, click Project > Build All.
If you want to open the project in Eclipse on Windows, you must run Eclipse from within [msys2](https://www.msys2.org/), in the mingw64 environment. You must also install the Qt5 library in the mingw64 environment.

## Building instructions
A Qt project file (.pro) is included. To build, open the terminal in the cloned directory and run `qmake` (you must have the Qt5 tools available). Then, run `make` (or `nmake` if building with MSVC).

In order to change the build configuration to debug (it is release by default) open the .pro file and change 'CONFIG += qt release' to 'CONFIG += qt debug'. 

## Build Requirements
- The Qt5 library (qtbase functionality is used)
- A c++11 compiler