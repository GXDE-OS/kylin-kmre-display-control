/* Copyright (C) 2011 The Android Open Source Project
**
** This software is licensed under the terms of the GNU General Public
** License version 2, as published by the Free Software Foundation, and
** may be copied, distributed, and modified under those terms.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/
#include "dll.h"

#include <stdlib.h>
#include <string.h>

/* Utility function, append one string to another, caller must free result */
static char*
append_string( const char* str1, const char* str2 )
{
    int   len1   = strlen(str1);
    int   len2   = strlen(str2);
    char* result = (char*)malloc(len1+len2+1);

    if (result != NULL) {
        memcpy(result, str1, len1);
        memcpy(result + len1, str2, len2);
        result[len1+len2] = '\0';
    }
    return result;
}


#include <dlfcn.h>
#include <stdlib.h>

ADynamicLibrary*
adynamicLibrary_open( const char*  libraryName,
                      char**       pError)
{
    char*  libName = (char*) libraryName;
    void*  result;

#define SO_EXTENSION ".so"

    /* Append a .so to the library name if it doesn't have an extension */
    if (strchr(libraryName,'.') == NULL) {
        libName = append_string(libraryName, SO_EXTENSION);
    }

    /* Now do our magic */
    *pError = NULL;
    result  = dlopen( libName, RTLD_LAZY );
    if (result == NULL) {
        *pError = strdup(dlerror());
    }

    /* Free the library name if we modified it */
    if (libName != (char*)libraryName) {
        free(libName);
    }

    return (ADynamicLibrary*) result;
}

void*
adynamicLibrary_findSymbol( ADynamicLibrary*  lib,
                            const char*       symbolName,
                            char**            pError)
{
    void* result;

    *pError = NULL;

    if (lib == NULL) {
        *pError = strdup("NULL library pointer");
        return NULL;
    }
    if (symbolName == NULL || symbolName[0] == '\0') {
        *pError = strdup("NULL or empty symbolName");
        return NULL;
    }
    result = dlsym(lib, symbolName);
    if (result == NULL) {
        *pError = strdup(dlerror());
    }
    return result;
}

/* Close/unload a given dynamic library */
void
adynamicLibrary_close( ADynamicLibrary*  lib )
{
    if (lib != NULL) {
        dlclose(lib);
    }
}

