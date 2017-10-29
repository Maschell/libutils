# libutils for WiiU homebrew.

This is a library for common functions.

## Features

- FS utility functions
- Wrapper for easy kernel read/write (KernelCopyData to copy data to any place)
- Multiple language support via gettext
- Common system functions (Exception handler, memory functions, Thread wrapper etc.)
- Built in function patcher engine
- String tools

(For some features the application need to be loaded from the homebrew_launcher to have kernel access)

## Logging usage
To able to use the logging, you need to compile the target application with follow C/C++ flag:
```
  -D__LOGGING__
```

Usage in the application:
```
log_init(); // Enables broadcast logging.
printf("Just prints this text\n");
DEBUG_FUNCTION_LINE("This prints my current function, file and line\n");
```

Read the logs via the [udp_debug_reader](https://github.com/dimok789/loadiine_gx2/tree/master/udp_debug_reader).

## Usage (TODO)

Link the application with

```
-lutils -ldynamiclibs
```

Check out the header for more information.

## Compiling

For compiling and using this lib, you need the [dynamic_libs](https://github.com/Maschell/dynamic_libs/tree/lib) installed to your portlibs folder.

Install this static library into your portlibs folder via: 

```
make && make install
```

## Dependencies

- Application needs to be loaded from the [homebrew_launcher](https://github.com/dimok789/homebrew_launcher)
- [dynamic_libs](https://github.com/Maschell/dynamic_libs/tree/lib) for access to the functions.

# Credits (TODO)

- Serveral users
