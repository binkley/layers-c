#include <stdio.h>

#include <gc.h>

#include "main.h"

int
main(int argc, char **argv) {
    printf("Hello, world, from [demo:%s:%d:%s] version %d!\n",
           __FILE__, __LINE__, __PRETTY_FUNCTION__, Demo_VERSION_MAJOR);
    return 0;
}
