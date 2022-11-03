# GUI Application to automatically copy a file to multiple locations once changed

## Usage
You can add files to be watched for changes by pressing '+'
You can add file paths to copy the watched file to by selecting it in the tree view and clicking '+ [watched file name]'. You can remove those file paths by selecting them and clicking '- [file path]'. You can also remove the files to be watched by clicking them and selecting '- [watched file name]'.


## Build configurationn
Since this project is not using the Qt library's make tools, you may need to configure some paths and copy some files in order to build this project. These are the paths you may need to configure:
- Under Project > Properties > C/C++ Build > Settings, under the Tool Settings menu:
	- C++ Compiler > Includes in the include paths (-I) box: /usr/include/x86_64-linux-gnu/qt5/. This should point at the Qt5 include directory. 
	- C++ Linker > Libraries in the Library search path (-L) box: /usr/lib/x86_64-linux-gnu/. This should point at the Qt5 lib directory.
- In src/meta.sh you may need to change moc to the absolute path of the Qt5 moc executable (located in the Qt5 bin directory or under /usr/lib/qt5/bin/ in Linux systems).

## Building instructions
*You may need to modify some project settings to be able to compile. See [Build configuration](#build-configuration)*
This project was created with [Eclipse CDT](https://projects.eclipse.org/projects/tools.cdt). In order to build it, you need to install this IDE (you need to install the Eclipse IDE and then add the CDT components to it). When everything is installed, you can select 'Open projects from file system' and choose the cloned directory. When it is opened, go to Project > Build Configurations > Set Active to set the desired target. Then, click Project > Build All.
If building on Windows, you must run Eclipse from within [msys2](https://www.msys2.org/), within the mingw64 environment. You must also install the Qt5 library in the mingw64 environment.

## Requirements
- The Qt5 dev library (core, gui and widgets components)
- A c++17 compliant compiler