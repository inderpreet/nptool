/**
 * @file    main.cpp
 * @description Entry Point File
*/
#include <app_config.h>
#include <stdio.h>
#include <utils.h>


int main(int argc, char *argv[]) {
    fprintf(stdout, "%s Version %d.%d\n",
            argv[0],
            APP_VERSION_MAJOR,
            APP_VERSION_MINOR);
    if (argc > 1){
        printf("\nArguments found\n");
        printf("%s\n", argv[0]);
        printf("%s\n", argv[1]);
    }
    printHello();   //!< Test setup by printing hello world.

    return 0;
}
