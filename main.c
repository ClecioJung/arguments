//------------------------------------------------------------------------------
// LIBRARIES
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
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

static int printVersion(const char *const arg)
{
    (void)arg;
    printf("[Version] %s\n", version);
    return EXIT_SUCCESS;
}


//------------------------------------------------------------------------------
// MAIN
//------------------------------------------------------------------------------

int main(const int argc, const char *const argv[])
{
    initArguments(printUsage, NULL);
    addArgument("--version", "-v", printVersion, "Display the software version.");
    parseArguments(argc, argv);

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// END
//------------------------------------------------------------------------------
