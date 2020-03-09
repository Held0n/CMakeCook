#include "Animal.hpp"
#include "Cat.hpp"

std::string Cat::name_impl() const {
    return "I'm " + name_ + " cat.";
}