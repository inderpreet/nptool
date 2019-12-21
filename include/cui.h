#ifndef _CUI_H
#define _CUI_H

#include <stdio.h>
#include <iostream>
#include <string>

int text_input();

/**
 * @brief   Class that contains CUI functionality
 */ 
class UserInput{
    private:
    static const std::string sTypes;
    int iSelection;
    std::string sProjectName;
    std::string sProjectType;


    public:
    // Getters
    int getSelection(){     return iSelection;      }
    std::string getProjectName(){return sProjectName;    }
    std::string getProjectType(){return sProjectType;    }

    // User interaction Methods
    void userProjectType();
    void userProjectName();
    void testSelection();
};

#endif
