#ifndef _NPTOOL_H
#define _NPTOOL_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <sys/stat.h>

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
};

#endif
