# libutils for WiiU homebrew. (WUT edition)
[![Build Status](https://travis-ci.org/Maschell/libutils.svg?branch=wut)](https://travis-ci.org/Maschell/libutils)  

This is a library for common functions.

## Features

- FS utility functions
- Multiple language support via gettext
- Common system functions (Exception handler, memory functions, Thread wrapper etc.)
- String tools

## Logging usage
To able to use the logging, you need to compile the target application with follow C/C++ flag:
```
  -D__LOGGING__
```

Usage in the application:
```
socket_lib_init();
log_init(); // Enables broadcast logging.
log_printf("Just prints this text\n");
DEBUG_FUNCTION_LINE("This prints my current function, file and line\n");
```

Read the logs via the [udp_debug_reader](https://github.com/dimok789/loadiine_gx2/tree/master/udp_debug_reader).

## Usage (TODO)

Link the application with

```
-lutilswut
```

You also need to add the include path to your Makefile. Example:

```
export INCLUDE	:= [...]  -I$(WUT_ROOT)/include/libutils
```

Check out the header for more information.

## Compiling

For compiling and using this lib, you need the [wut](https://github.com/decaf-emu/wut) installed.

Install this static library into your wut folder via: 

```
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=$WUT_ROOT/share/wut.toolchain.cmake -DCMAKE_INSTALL_PREFIX=$WUT_ROOT ../
make install
```

## Dependencies

- [wut](https://github.com/decaf-emu/wut)

# Credits (TODO)

- Serveral users
