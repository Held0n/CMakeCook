#pragma once

#include <iosfwd>
#include <string>

class Message {
public:
    Message(const std::string &m) : m_message(m) {}
    friend std::ostream &operator<<(std::ostream &os, Message &obj) {
        return obj.printObject(os);
    }

private:
    std::string m_message;
    std::ostream &printObject(std::ostream &os);
};