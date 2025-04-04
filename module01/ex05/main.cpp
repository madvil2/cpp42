#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Harl harl;
    
    if (argc == 1) {
        std::cout << "Testing all complain levels:" << std::endl;
        std::cout << "------------------------" << std::endl;
        
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        harl.complain("UNKNOWN");
    }
    else {
        for (int i = 1; i < argc; i++) {
            harl.complain(argv[i]);
        }
    }
    
    return 0;
}