/**
*	@file   parseArgs.h
*	@brief	This file contains the argument parser class
*
*
*	@author Inderpreet Singh
*/
#ifndef _PARSEARGS_H_
#define _PARSEARGS_H_

#include <iostream>
#include <vector>
#include <string>


/**
 * @brief   Class for parsing command line arguments
 */
class Parser{
    private:
        int argc;       //!< Variable to store argument count
        char **argv;    //!< Pointer to list of arguments
        std::vector<std::string> allargs;

    public:
        Parser();
        Parser(int argc, char **argv);
        void printAllArgs();
        bool findFlag(std::string, std::string);

        /** 
         * @brief getter to be used with range based for loop
         * @return Returns a vector of strings
         */
        std::vector < std::string > getAllArgs() &&{
            return allargs;
        }

        /** getter to reference to internal element
         *  @return Returns a reference to vector of strings
         */
        const std::vector<std::string>& getAllArgs() const& {
            return allargs;
        }
};

#endif
