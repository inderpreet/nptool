/**
*	@file   actions.cpp
*	@brief	This file contains the class and methods for actions to 
*           be performed as per arguments
*
*	@author Inderpreet Singh
*/
#include "actions.h"

typedef void(* f_void)(void);

void testFunction(){
    std::cout << "Test Function" << std::endl;
}
f_void f1_ptr = &testFunction;

void testerFunction(void (*fn)(void)){
    (*fn)();
}
void testerAgain(f_void fn){
    (*fn)();
}

// usage
// testerFunction(f1_ptr);
// testerAgain(f1_ptr);

