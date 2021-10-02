//------------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arguments.h"

//------------------------------------------------------------------------------
// GLOBAL VARIABLES
//------------------------------------------------------------------------------

static const char *const version = "1.0.0";

//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------

static int printUsage(const char *const software)
{
    printf("[Usage] %s [script.b] [Options]\n", software);
    return EXIT_SUCCESS;
}

static int defaultAction(const char *const arg)
{
    printf("Unrecognized argument: %s\n", arg);
    return EXIT_SUCCESS;
}

static int printVersion(const char *const arg)
{
    (void)arg;
    printf("[Version] %s\n", version);
    return EXIT_SUCCESS;
}

static int displayDate(const char *const arg)
{
    (void)arg;
    printf("Current date: %s\n", version);
    return EXIT_SUCCESS;
}

static int displayTime(const char *const arg)
{
    (void)arg;
    printf("Current time: %s\n", version);
    return EXIT_SUCCESS;
}

static int increment(const char *const arg)
{
    const char *ptr = strchr(arg, '=');
    int value = atoi(++ptr);
    printf("Incrementing one to %d results in %d\n", value, value+1);
    return EXIT_SUCCESS;
}

static int decrement(const char *const arg)
{
    const char *ptr = strchr(arg, '=');
    int value = atoi(++ptr);
    printf("Decrementing one to %d results in %d\n", value, value-1);
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// MAIN
//------------------------------------------------------------------------------

int main(const int argc, const char *const argv[])
{
    initArguments(printUsage, defaultAction);
    addArgument("--version", "-v", printVersion, "Display the software version.");
    addArgument("--date", "-d", displayDate, "Display the current date.");
    addArgument("--time", "-t", displayTime, "Display the current time.");
    addArgument("--inc=%d", "-i=%d", increment, "Increment one to the value passed as argument.");
    addArgument("--dec=%d", "-d", decrement, "Decrement one to the value passed as argument.");
    parseArguments(argc, argv);

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// END
//------------------------------------------------------------------------------
