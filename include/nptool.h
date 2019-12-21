#ifndef _NPTOOL_H
#define _NPTOOL_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <cstdio>
#include <fstream>

class Nptool{
    private:
    std::string sPath;

    public:
    Nptool(){ sPath = "/home/ipv1/workspace/sandbox/test_project"; }
    
    std::string getPath(){ return sPath; }
    void printPath(){ std::cout << sPath; }
    
    bool checkPath(){ 
        struct stat buffer;
        return ( stat(sPath.c_str(), &buffer) == 0 );
        // returns true if path exists
    }

    bool createIfDoesNotExist(){
        if( !checkPath() ){
            int status = mkdir(sPath.c_str(), 0777);
            if( status != 0 ){
                std::cout << "\n Error Creating directory";
                return 0;
            } else 
                return -1;
        } else {
            std::cout << "Folder already exisits";
            return -2;
        }
    }

    bool copyFile(std::string src, std::string dest){
        // try?
        std::ifstream srcs(src, std::ios::in); // ifstream src("file.txt", std::ios::binary);
        std::ofstream dsts(dest, std::ios::out);

        dsts << srcs.rdbuf();
        srcs.close();
        dsts.close();

        return true;
    }

};

#endif
