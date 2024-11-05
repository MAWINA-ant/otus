#include <iostream>
#include <queue>
#include <chrono>
#include <fstream>

#include "command.h"

int countCommands = 0;

/// @brief Печатает команды в очереди и пишет лог файл
/// @param commands Очередь команд
/// @param fileName Имя лог файла
void printCommands(std::queue<Command>& commands, std::string& fileName) {
    if (commands.empty() || fileName.empty()) return;
    std::ofstream out;
    out.open(fileName);
    std::cout << "bulk: ";
    out << "bulk: ";
    while (!commands.empty()) {
        std::cout << commands.front();
        out << commands.front();
        if (commands.size() != 1) {
            std::cout << ", ";
            out << ", ";
        }
        commands.pop();
    }
    std::cout << "\n";
}

/// @brief Вычисляет текущее время Unix
/// @return Вовращает строку времени Unix
std::string currentUnixTimeString() {
    std::time_t result = std::time(nullptr);
    return std::to_string(result);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not anought arguments! Minimum 2 (for example ./bulk 3)\n";
        return 1;
    }
    countCommands = std::atoi(argv[1]); 
    if (!countCommands) {
        std::cout << "Second argument should be a number\n";
        return 1;
    }
    std::string fileName = "";
    std::queue<Command> queueCommands;
    u_int8_t nestedLevel = 0;
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line == "{") {
            ++nestedLevel;
            if (queueCommands.front().getLevel() == 0) {
                printCommands(queueCommands, fileName);    
            }
            continue;
        } else if (line == "}") {
            --nestedLevel;
            if (queueCommands.front().getLevel() == 0 || nestedLevel == 0) {
                printCommands(queueCommands, fileName);
            }
        } else {
            if (queueCommands.empty()) {
                fileName = "bulk" + currentUnixTimeString();
            }
            queueCommands.push(Command{line, nestedLevel});
        }
        if (queueCommands.size() == countCommands && queueCommands.front().getLevel() == 0) {
            printCommands(queueCommands, fileName);
        }
    }
    if (queueCommands.front().getLevel() == 0) {
        printCommands(queueCommands, fileName);
    }
    return 0;
}
