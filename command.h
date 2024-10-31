#ifndef COMMAND_H
#define COMMAND_H
#pragma once

#include <string>

class Command
{
public:
    Command();
    Command(const std::string& name, u_int8_t level);
    ~Command();
    u_int8_t getLevel() const { return nestedLevel; }

    friend std::ostream& operator <<(std::ostream& os, const Command& obj) {
        os << obj.commandName;
        return os;
    }

private:
    std::string commandName;
    u_int8_t nestedLevel{0};
};



#endif