#include "geometry_circle.hpp"
#include "geometry_polygon.hpp"

#include <cstdlib>
#include <iostream>

int main() {
    using namespace geometry;
    
    double radius   = 2.5293;
    double A_circle = area::circle(radius);
    std::cout << "A circle of radius " << radius << " has an area of "
    << std::endl;

    int nSides = 19;
    double side = 1.29312;
    double A_polygon = area::polygon(nSides, side);
    std::cout << "A regular polygon of " << nSides << " sides of length "
    << side << " has an area of " << A_polygon << std::endl;

    return EXIT_SUCCESS;
} 