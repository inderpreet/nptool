/**
*	@file   cui.cpp
*	@brief	Command Line Inputs and all that jazz
*
*	@author Inderpreet Singh
*/
#include "cui.h"

const std::string UserInput::sTypes = "1. Blank Project \n2. C++ Project \n3. Python Project \n4. Docker Project\n";

//! Method for getting project Name from user
void UserInput::userProjectName(){
    std::cout << "Enter Project Name : ";
    std::cin >> this->sProjectName;
}

void UserInput::userProjectType(){
    std::string in1;
    int selection{0};

    std::cout << sTypes;
    std::cout << "Enter Selection : ";
    std::cin >> in1;
    
    if ( in1 == "x"){
        std::cout << "\nExiting\n";
        exit(0);
    } else {
        try{ // convert the string to integer
            selection = std::stoi(in1);
        } catch (std::invalid_argument const &e) {
		    std::cout << "Bad input: std::invalid_argument thrown" << '\n';
	    } catch (std::out_of_range const &e) {
		    std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
	    }
        this->iSelection = selection;
        this->testSelection();
    }
}

void UserInput::testSelection(){
    switch (this->iSelection){
        case 1:
            std::cout << "Creating blank project\n";
            // @TODO Add function to create a blank project
            break;
        case 2:
            std::cout << "Creating C++ Project\n";
            break;
        case 3:
            std::cout << "Creating Python Project\n";
            break;
        case 4:
            std::cout << "Creating Docker Project\n";
            break;
        default:
            std:: cout<< "Unrecognized option\n";
    }
}

//! Method for getting project Type selection from user
//! Depreciated
int text_input(){
    std::string in1;
    int selection{0};
    std::cout << "1. Blank Project\n";
    std::cout << "2. cpp cmake Project\n";
    std::cout << "3. cpp OpenCV Project\n";
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
            // @TODO Add function to create a blank project
            break;
        default:
            std:: cout<< "Unrecognized option\n";
    }

    return selection;
}


