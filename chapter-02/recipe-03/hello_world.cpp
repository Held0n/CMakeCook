#include <cstdlib>
#include <iostream>
#include <string>

std::string say_hello() {
    #ifdef IS_INTEL_CXX_COMPILER
        return std::string("Hello Intel compiler!");
    #elif IS_GNU_CXX_COMPILER
        return std::string("Hello GNU compiler!");
    #elif IS_PGI_CXX_COMPILER
        return std::string("Hello PGI compiler!");
    #else
        return std::string("Hello unknown compiler!");
    #endif
}

int main() {
    std::cout << say_hello() << std::endl;
    std::cout << "compiler name is " COMPILER_NAME << std::endl;
    return EXIT_SUCCESS;
}