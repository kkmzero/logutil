# logutil

Utility for creating log files in C++ projects, licensed under [zlib license](LICENSE). Tested on Linux, Windows and BSD operating systems.

## Installation

You can use logutil simply by copying folder ```logutil``` to your desired location. Then in your project include it with line:</br>
```#include "logutil/logutil.hpp"```

Makefile is included in the repository and command ```make install``` copies file to ```/usr/local/include/``` folder by default. This default path can be changed by editing variable ```DEST_PATH``` in Makefile.

**Note:** copy command is set to copy file ```logutil.hpp``` and rename it to ```logutil```.</br>It is done this way so logutil can be used in projects by including it with line: ```#include <logutil>```

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

In case you need check logutil version in your program, you have to define ```LOGUTIL_USE_INFO``` before including logutil file. 
