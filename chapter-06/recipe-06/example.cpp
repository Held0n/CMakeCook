#include "version.hpp"
#include <iostream>

int main() {
    std::cout << "This code has been configured from version " << GIT_HASH << std::endl;
}