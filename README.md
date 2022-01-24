# Logutil

Utility for creating log files in C++ projects, licensed under [zlib license](LICENSE). Tested on Linux, Windows and BSD operating systems.

## Installation

You can use Logutil simply by copying ```logutil``` directory to your desired location. Then in your project include it with line pointing to correct file, similar to this one:
```c++
#include "logutil/logutil.hpp"
```
</br>

Makefile is included in the repository and command ```make install``` copies file ```logutil.hpp``` to ```/usr/local/include/``` directory and renames it to ```logutil``` by default. Install path can be changed by editing variable ```DEST_PATH``` in Makefile. It is done this way so Logutil can be used in projects by including it with line:
```c++
#include <logutil>
```

## Functions

### Opening, Closing and Writing to a File

For opening file use function ```logutil::file_open("filename.log");```</br>
You are then able to write strings in specified file with function ```logutil::write("string goes here");```</br>
Function ```logutil::file_close();``` closes the file handle.

Alternatively, you can use function ```write_to_file``` which takes care of opening and closing file handle automatically:</br>
```logutil::write_to_file("string goes here", "filename.log");```

### Logging errors

You can use built-in macro ```__error(function)``` for debugging your code. It passes name of your function and outputs it + writes to log file a message in cases when compiler runs into error.

### Clearing the File

If you need to clear the log file, you can use function ```file_clear("filename.log");```

### Checking for version

Current version of Logutil is set in varios macros:

```c++
LOGUTIL_VERSION_MAJOR
LOGUTIL_VERSION_MINOR
LOGUTIL_VERSION_PATCH
LOGUTIL_VERSION_STRING
LOGUTIL_VERSION_MAKE
```
