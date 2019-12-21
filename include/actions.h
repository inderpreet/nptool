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
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
//#include <experimental/filesystem>
//namespace fs = std::experimental::filesystem;


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
        std::ifstream in_file;
        std::ofstream out_file;

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

        //! @brief Function to test system.
        void showAllArgs(){
            for (auto &a: vsArguments){
                std::cout << a << std::endl;
            }
        }

        //! @brief  Wrapper for method to create directory
        int create_folder(const char* _fname){
            int status = mkdir(_fname, 0777);
            if ( status > 0 )
                std::cout << "Error Creating Folder" << std::endl;
            return 0;
        }

        //! @brief Function to replace a sub-string with another
        bool replace(std::string& str, const std::string& from, const std::string& to) {
            size_t start_pos = str.find(from);
            if(start_pos == std::string::npos)
                return false;
            str.replace(start_pos, from.length(), to);
            return true;
        }

        //! @brief  Function to generate a README.md from template file
        void readme(std::string path){
            std::string readme{std::move(path)};
            readme.append("/README.md");
            
            in_file.open("~/nptool/templates/blank/README.md");
            out_file.open(readme);
            
            for ( std::string l; getline(in_file, l); ){
                replace(l, "Project Title", "New Proj");
                std::cout << l << std::endl;
                out_file << l << std::endl;
            }
            in_file.close();
            out_file.close();
        }

        //! @brief  Method to create a blank project
        int create_blank_project(std::string n){
            const char *homedir;
            if ((homedir = getenv("HOME")) == NULL){
                homedir = getpwuid(getuid()) -> pw_dir;
            }

        //! Step 1: Create a New Folder for the Project
            std::string name{std::move(n)};
            name.insert(0, "./");
            const char *nptr = name.c_str();
            create_folder(nptr);

        //! Step 2: Copy README.md with modified heading
            readme(name);

        //! Step 3: Copy License and .gitignore
            name += "/.gitignore";
            // c++17 onwards
            // try{
            //     fs::copy_file("./templates/blank/.gitignore", name);
            // } catch(fs::filesystem_error& e) {
            //     std::cout << "Could not Copy .gitignore: " << e.what() << std::endl;
            // }
            std::ifstream src("~/nptool/templates/blank/.gitignore", std::ios::binary);
            std::ofstream dst(name, std::ios::binary);
            dst << src.rdbuf();
            src.close();
            dst.close();

            replace(name, ".gitignore", "LICENSE.txt");
            src.open("~/nptool/templates/blank/LICENSE.txt", std::ios::binary);
            dst.open(name, std::ios::binary);
            dst << src.rdbuf();
            src.close();
            dst.close();

            return 0;
        }
};


#endif

