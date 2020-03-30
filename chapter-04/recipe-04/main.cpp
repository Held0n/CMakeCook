#include "sum_integers.hpp"

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    std::vector<int> integers;
    for(auto i = 1; i < argc; ++i) {
        integers.push_back(i);
    }
    auto sum = sum_integers(integers);
    std::cout << sum << std::endl;
}