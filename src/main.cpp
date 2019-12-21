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
#include "help.h"
#include "nptool.h"

const char *cptrTitle = "New Project Tool";


int main(int argc, char *argv[]) {
    //printHello();   //! Test setup by printing hello world.
    std::cout << cptrTitle << "\nVersion " << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << std::endl << std::endl;

    if (argc > 1){
        Parser parser(argc, argv);
        if ( parser.findFlag("-h", "--help") == true ){
            print_help();
        }
        
        if ( parser.findFlag("-n", "-name") == true ){
            std::cout << std::endl << "Found name" << std::endl;
        }
        
        // if ( parser.findFlag("-t", "-type") == true ){
        //     std::cout << std::endl << "Found type" << std::endl;
        // }

        Actions actions(parser.getAllArgs());
        //actions.showAllArgs();
        //actions.read_template();
        std::string name{"New Project"};
        actions.create_blank_project(name);
    } else {    // No Arguments Found
        // text_input(); // Depreciated
        // UserInput userInput;
        // userInput.userProjectName();
        // userInput.userProjectType();
        Nptool nptool;
        nptool.printPath();
        nptool.createIfDoesNotExist();

        nptool.copyFile("README_template.md", "README.md");
        std::cout << std::endl;

    }
    return 0;
}
