# Arguments

## Overview

**Arguments** is a simple C library for parsing command line arguments. Ir posseses the following characteristics:

- Compatible with C89;
- Command arguments are added to the library dinamically;
- The library accept an unlimited number of commands;
- Each command may accept parameters received by the command line (example: `--value=100`);

## Usage example

In order to use this library in your project, just donwload the files `arguments.h` and `arguments.c`, paste them on your project folder and include the header file in your source code:

```c
#include "arguments.h"
```

At the begining of your code, initialize the library using the function `initArguments()` passing two functions as parameters. The first function must print a helper message to the user teaching him to use your software (call your software using the argument `--help` or `-h` to see this message). The second function will be called in case the library unrecognizes an argument passed by the user. You also have the option to pass `NULL` as argument to the `initArguments()` function, if you don't want to treat this cases.

After initializing the library, call the function `parseArguments(argc, argv)` passing the main arguments. This will parse the command line arguments and execute the correct functions in each case. Here's an example:

```c
int printUsage(const char *const software)
{
    printf("[Usage] %s [Options]\n", software);
    return EXIT_SUCCESS;
}

int defaultAction(const char *const arg)
{
    printf("Unrecognized argument: %s\n", arg);
    return EXIT_SUCCESS;
}

int main(const int argc, const char *const argv[])
{
    initArguments(printUsage, defaultAction);
    parseArguments(argc, argv);
    return EXIT_SUCCESS;
}
```

In order to register the commands you want your software to accept, use the function `addArgument()`, and passing as arguments the command you want to accept (`--version`), a simple alias for that command (`-v`), a function to be called in case this command or alias are detected, and a string giving a description of this command. Example:

```c
int printVersion(const char *const arg)
{
    (void)arg;
    printf("[Version] 1.0.0\n");
    return EXIT_SUCCESS;
}

int main(const int argc, const char *const argv[])
{
    initArguments(printUsage, defaultAction);
    addArgument("--version", "-v", printVersion, "Display the software version.");
    parseArguments(argc, argv);
    return EXIT_SUCCESS;
}
```

All the functions passed to the function `addArgument()` must return `EXIT_SUCCESS` in case you wish the library to continue to parse more arguments, and `EXIT_FAILURE` in case you wish it to stop. If an unrecognized argument is detected, the function passed as the second argument of `initArguments()` is called. In case this function returns `EXIT_SUCCESS` the parsing of arguments continues, and if it returns `EXIT_FAILURE`, the parsing of arguments stops. If you pass `NULL` as the second parameter of `initArguments()`, the parsign of arguments stops and an helper message is shown, like this:

```
Unknown argument: abc
[Usage] ./test_arguments [Options]
[Options]:
	--help     or -h  : Display this help message.
	--version  or -v  : Display the software version.
```

If you wish to implement a command that may accept parameters received by the command line (example: --value=100), just end the first argument passed to the function `addArgument()` with an equal sign (`=`), like so:

```c
int printValue(const char *const arg)
{
    const char *ptr = strchr(arg, '=');
    int value = atoi(++ptr);
    printf("Value: %d\n", value);
    return EXIT_SUCCESS;
}

int main(const int argc, const char *const argv[])
{
    initArguments(printUsage, defaultAction);
    addArgument("--value=", "-v", printValue, "Displays the value passed as parameter.");
    parseArguments(argc, argv);
    return EXIT_SUCCESS;
}
```

Check the file `test.c` for an complete example of usage. In order to run the test suite, just download this project and compile the example using the command `make` in its folder.