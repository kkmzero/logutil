# Logutil

Library for creating log files in C++ projects, licensed under [zlib license](LICENSE). Tested on Linux, Windows and BSD operating systems.

## Installation

You can use Logutil simply by copying ```logutil``` directory to your desired location. Then in your project include the file ```logutil.hpp``` with line pointing to its correct path, similar to this one:
```c++
#include "logutil/logutil.hpp"
```
</br>

Makefile is included in the repository and command ```make install``` copies file ```logutil.hpp``` to ```/usr/local/include/``` directory and renames it to ```logutil``` by default. Install path can be changed by editing variable ```DEST_PATH``` in Makefile. It is done this way so Logutil can be used in projects by including it directly without additional parameters/flags with line:
```c++
#include <logutil>
```

## Functions

### Opening, Closing and Writing to a File

For opening file use function ```file_open```, then you are able to write strings to specified file with ```write``` function.</br>
Function ```file_close``` closes the filehandle at the end.

**Example:**
```c++
logutil::file_open("filename.log");
logutil::write("Hello, World!");
logutil::file_close();
```
</br>Alternatively, you can use only one function ```write_to_file``` which takes care of opening and closing the filehandle automatically:</br>
```c++
logutil::write_to_file("Hello, World!", "filename.log");
```

### Controlling Filehandle

Logutil uses one filehandle for file operations: ```static std::fstream filehandle{};```. You can check whether this filehandle is open or not with function ```is_file_open```.

### Logging errors

If you need more detailed debugging and logging, you can use built-in function ```check_function```.

**Example:**
```c++
logutil::check_function(__FUNCTION__, __FILE__, __LINE__, "filename.log");
```

with example output:
```
Error in Function __testfunc in file: test.cpp on line 20
```

### Clearing the File

If you need to clear the log file completely, you can use function:
```c++
file_clear("filename.log");
```

### Checking for version

Current version of Logutil is set in varios macros:

```c++
#define LOGUTIL_VERSION_MAJOR  (int)
#define LOGUTIL_VERSION_MINOR  (int)
#define LOGUTIL_VERSION_PATCH  (int)
#define LOGUTIL_VERSION_STRING (str)
#define LOGUTIL_VERSION_MAKE   (int)
```
