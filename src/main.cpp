/**
 * @file    main.cpp
 * @description Entry Point File
*/
#include <app_config.h>
#include <stdio.h>
#include <utils.h>
#include <parseArgs.h>
#include "cui.h"
#include "actions.h"

const char *cptrTitle = "New Project Tool";


int main(int argc, char *argv[]) {
    //printHello();   //! Test setup by printing hello world.
    std::cout << cptrTitle << "\nVersion " << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << std::endl << std::endl;

    if (argc > 1){
        Parser parser(argc, argv);
        if ( parser.findFlag("-h", "-help") == true ){
            // fprintf(stdout, "%s Version %d.%d\n",
            //     cptrTitle,
            //     APP_VERSION_MAJOR,
            //     APP_VERSION_MINOR);
            std::cout << argv[0];
            std::cout << "Usage: \"nptool [OPTION...]\"" << std::endl;
            std::cout << "Example Usage: \"nptool -n Project_Title -t cpp\"" << std::endl << std::endl;
            std::cout << "\t-n\t Name of the Project" << std::endl;
            std::cout << "\t-t\t Type of the project" << std::endl;
        }
        
        // if ( parser.findFlag("-n", "-name") == true ){
        //     std::cout << std::endl << "Found name" << std::endl;
        // }
        
        // if ( parser.findFlag("-t", "-type") == true ){
        //     std::cout << std::endl << "Found type" << std::endl;
        // }

        Actions actions(parser.getAllArgs());
        //actions.showAllArgs();
        //actions.read_template();
        std::string name{"New Project"};
        actions.create_blank_project(name);
    } else {    // No Arguments Found
        text_input();
    }
    return 0;
}
