#ifndef COMMAND_H
#define COMMAND_H
#pragma once

#include <string>
#include <chrono>
#include <fstream>

class Command
{
public:
    Command() {}
    Command(const std::string& name, std::time_t time, uint8_t level = 0) : 
                                                                            commandName{name}, 
                                                                            commandTime{time}, 
                                                                            nestedLevel{level} {}
    ~Command() {}
    inline uint8_t getLevel() const { return nestedLevel; }
    inline std::time_t getTime() const { return commandTime; }

    friend std::ostream& operator <<(std::ostream& os, const Command& obj) {
        os << obj.commandName;
        return os;
    }

private:
    /// @brief Текст команды
    std::string commandName;
    /// @brief Время команды
    std::time_t commandTime;
    /// @brief Уровень вложенности команды
    uint8_t nestedLevel{0};
};



#endif