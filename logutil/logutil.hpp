/*
 * Logutil: Library for creating log files in C++ projects.
 *
 * Copyright (c) 2020 - 2022, Ivan Kmeťo
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */


#ifndef __LOGUTIL__LOGUTIL_HPP
#define __LOGUTIL__LOGUTIL_HPP

#include <string>
#include <fstream>

#define LOGUTIL_VERSION_MAJOR   2
#define LOGUTIL_VERSION_MINOR   0
#define LOGUTIL_VERSION_PATCH   0
#define LOGUTIL_VERSION_STRING  "2.0.0"
#define LOGUTIL_VERSION_MAKE    (((LOGUTIL_VERSION_MAJOR) << 22) | ((LOGUTIL_VERSION_MINOR) << 12) | (LOGUTIL_VERSION_PATCH))

static std::fstream filehandle{};


namespace logutil {
    inline bool is_file_open() {
        return filehandle.is_open() ? true : false;
    }

    inline bool file_open(std::string filename) {
        if (!filehandle.is_open()) {
            filehandle.open(filename.c_str(), std::ios_base::app | std::ios::out);
            std::ios_base::sync_with_stdio(false);
            filehandle.imbue(std::locale(""));
            return true;
        }
        return false;
    }

    inline bool file_close() {
        if (filehandle.is_open()) {
            filehandle.close();
            return true;
        }
        return false;
    }

    inline bool write(std::string text) {
        if (filehandle.is_open()) {
            filehandle << text << "\n";
            return true;
        }
        return false;
    }

    inline bool file_clear(std::string filename) {
        if (filehandle.is_open()) {
            file_close();
        }

        filehandle.open(filename.c_str(), std::ios_base::out | std::ios::trunc);
        filehandle.close();
        return true;
    }

    inline bool write_to_file(std::string text, std::string filename) {
        if (!filehandle.is_open()) {
            file_open(filename);
        }

        filehandle << text << "\n";
        filehandle.close();
        return true;
    }

    inline bool check_function(std::string function, std::string file, int line, std::string filename) {
        std::string output = "Error in Function " + function + " in file: " + file
                             + " on line " + std::to_string(line) + "\n";

        write_to_file(output, filename);
        return true;
    }
}


#endif
