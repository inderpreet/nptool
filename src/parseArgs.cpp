/**
*	@file   parseArgs.cpp
*	@brief	This file contains the argument parser class
*
*
*	@author Inderpreet Singh
*/

#include <iostream>
#include <parseArgs.h>

//! @brief Default Constructor
Parser::Parser(){}

//! @brief  Constructor
Parser::Parser(int argc, char **argv) : argc{ std::move(argc)}, argv{ std::move(argv)} {
    allargs.assign(argv + 1, argv + argc);
}

/**
 * @brief   Function to print all arguments
 */ 
void Parser::printAllArgs(){
    for (const std::string str: allargs){
        std::cout << str << std::endl;
    }
}

/**
 * @brief   Function to find a specific flag
 */ 
bool Parser::findFlag(std::string singleChar, std::string longName){
    bool bFlagFound = false;
    std::string sParameter{};
    for ( auto const& s : allargs ) {
        if ( bFlagFound == true && s != ""){
            sParameter = s;
            std::cout << std::endl << sParameter << std::endl;
            break;
        }
        if (!s.compare(singleChar) || !s.compare(longName) ) {
            bFlagFound = true;
        }
    }
    return bFlagFound;
}

