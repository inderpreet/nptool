/**
*	@file   actions.cpp
*	@brief	This file contains the class and methods for actions to 
*           be performed as per arguments
*
*	@author Inderpreet Singh
*/
#ifndef _ACTIONS_H
#define _ACTIONS_H

#include <iostream>
#include <string>
#include <assert.h>
#include <vector>


typedef enum ProjectTypes{
            BLANK, CPP_CMAKE, CPP_OPENCV, PYTHON3_DOCKER, PYTHON3_FLASK
            };

/**
 * @brief   Class containing actions to be performed by the tool
 */ 
class Actions{
    private:
        std::string sProjectName;
        std::string sProjectPath;
        ProjectTypes eProjectType;
        std::vector <std::string> vsArguments;
    public:

        /**
         * @brief   Default Constructor
         */      
        Actions(){
            sProjectName = std::move("NewProject");
        }

        /**
         * @brief   Constructor with argument for setting vector of strings which
         *          contains arguments passed.
         */
        Actions( std::vector <std::string> n): vsArguments{std::move(n)}{
            // assert (n.size() > 0);
        }

        /** 
         * @brief   Constructor with single string argument for setting
         *          project name
         */ 
        Actions(std::string n) : sProjectName{std::move(n)}{
            assert (n.size() > 0);
        }

        // setter for Project Name
        void setProjectName(std::string n) {
            assert (n.size() > 0);
            sProjectName = std::move(n);
        }

        // getter for Project Name
        std::string getProjectName() &&{
            return sProjectName;
        }
        const std::string& getProjectName() const&{
            return sProjectName;
        }

        // setter for Project Path
        void setProjectPath(std::string n){
            assert (n.size() > 0);
            sProjectPath = std::move(n);
        }

        // getter for Project Path
        std::string getProjectPath() &&{
            return sProjectPath;
        }
        const std::string& getProjectPath() const&{
            return sProjectPath;
        }

        // setter for project type
        void setProjectType(ProjectTypes t){
            eProjectType = std::move(t);
        }

        // getters: First one not necessary here since 
        // we cant use range based for loop on it.
        ProjectTypes getProjectType() &&{
            return eProjectType;
        }
        const ProjectTypes& getProjectType() const&{
            return eProjectType;
        }

        void showAllArgs(){
            for (auto &a: vsArguments){
                std::cout << a << std::endl;
            }
        }
};


#endif

