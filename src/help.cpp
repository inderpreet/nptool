
#include "help.h"

void print_help(){
    // fprintf(stdout, "%s Version %d.%d\n",
    //     cptrTitle,
    //     APP_VERSION_MAJOR,
    //     APP_VERSION_MINOR);
    std::cout << "Usage: \"nptool [OPTION...]\"" << std::endl;
    std::cout << "Example Usage: \"nptool -n Project_Title -t cpp\"" << std::endl << std::endl;
    std::cout << "\t-n\t Name of the Project" << std::endl;
    std::cout << "\t-t\t Type of the project" << std::endl;
}
