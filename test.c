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

const char *const version = "1.0.0";
int first = 0;
int second = 0;

//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------

int printUsage(const char *const software)
{
    printf("[Usage] %s [Options]\n", software);
    return EXIT_SUCCESS;
}

int defaultAction(const char *const arg)
{
    printf("Unrecognized argument: %s\n", arg);
    return EXIT_FAILURE;
}

int printVersion(const char *const arg)
{
    (void)arg;
    printf("[Version] %s\n", version);
    return EXIT_SUCCESS;
}

int displayDate(const char *const arg)
{
    (void)arg;
    printf("Current date: %s\n", version);
    return EXIT_SUCCESS;
}

int displayTime(const char *const arg)
{
    (void)arg;
    printf("Current time: %s\n", version);
    return EXIT_SUCCESS;
}

int increment(const char *const arg)
{
    const char *ptr = strchr(arg, '=');
    int value = atoi(++ptr);
    printf("Incrementing one to %d results in %d\n", value, value+1);
    return EXIT_SUCCESS;
}

int decrement(const char *const arg)
{
    const char *ptr = strchr(arg, '=');
    int value = atoi(++ptr);
    printf("Decrementing one to %d results in %d\n", value, value-1);
    return EXIT_SUCCESS;
}

int firstValue(const char *const arg)
{
    const char *ptr = strchr(arg, '=');
    int value = atoi(++ptr);
    first = value;
    printf("Atributing %d to the variable 'first'\n", value);
    return EXIT_SUCCESS;
}

int secondValue(const char *const arg)
{
    const char *ptr = strchr(arg, '=');
    int value = atoi(++ptr);
    second = value;
    printf("Atributing %d to the variable 'second'\n", value);
    return EXIT_SUCCESS;
}

int sumValues(const char *const arg)
{
    (void)arg;
    printf("The sum of the global variables 'first' and 'second' is %d\n", first+second);
    return EXIT_SUCCESS;
}

int subtractValues(const char *const arg)
{
    (void)arg;
    printf("The subtraction of the global variables 'first' and 'second' is %d\n", first-second);
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// MAIN
//------------------------------------------------------------------------------

int main(const int argc, const char *const argv[])
{
    initArguments(printUsage, defaultAction);
    addArgument("--version", "-v", printVersion, "Display the software version.");
    addArgument("--date", NULL, displayDate, "Display the current date.");
    addArgument("--time", "-t", displayTime, "Display the current time.");
    addArgument("--inc=", "-i=", increment, "Increment one to the value passed as argument.");
    addArgument("--dec=", "-d", decrement, "Decrement one to the value passed as argument.");
    addArgument("--first=", "-f", firstValue, "Atributes the value passed as argument to the global variable 'first'.");
    addArgument("--second=", "-s", secondValue, "Atributes the value passed as argument to the global variable 'second'.");
    addArgument("--sum", NULL, sumValues, "Returns the sum of the global variables 'first' and 'second'.");
    addArgument("--subtract", NULL, subtractValues, "Returns the subtraction of the global variables 'first' and 'second'.");
    parseArguments(argc, argv);

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// END
//------------------------------------------------------------------------------
