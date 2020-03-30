#include "sum_integers.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>

TEST_CASE("sum of integers for a short vector", "[short]") {
    auto integers = {1, 2, 3, 4, 5};
    REQUIRE(sum_integers(integers) == 15);
}

TEST_CASE("sum of integers for a long vector", "[long]") {
    std::vector<int> integers;
    for(int i = 1; i < 1001; ++i) {
        integers.push_back(i);
    }
    REQUIRE(sum_integers(integers) == 500500);
}