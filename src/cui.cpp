/**
*	@file   cui.cpp
*	@brief	Command Line Inputs and all that jazz
*
*	@author Inderpreet Singh
*/
#include "cui.h"
#include <iostream>
#include <string>

int text_input(){
    std::string in1;
    int selection{0};
    std::cout << "1. Blank Project\n";
    std::cout << "x. Exit\n\n";

    std::cout << "Enter Selection : ";
    std::cin >> in1;
    
    if ( in1 == "x"){
        std::cout << "\nExiting\n";
        exit(0);
    } else {
        try{
            selection = std::stoi(in1);
        } catch (std::invalid_argument const &e) {
		    std::cout << "Bad input: std::invalid_argument thrown" << '\n';
	    } catch (std::out_of_range const &e) {
		    std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
	    }

    }

    switch (selection){
        case 1:
            std::cout << "Creating blank project\n";
            break;
        default:
            std:: cout<< "Unrecognized option\n";
    }

    return selection;
}


