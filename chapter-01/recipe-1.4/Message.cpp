#include "Message.hpp"

#include <iostream>
#include <string>

std::ostream &Message::printObject(std::ostream &os) {
    os << "This is my very nice message: " << std::endl;
    os << m_message;
    return os;
}