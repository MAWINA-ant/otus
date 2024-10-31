#include <iostream>
#include <queue>

#include "command.h"

int countCommands = 0;

void printCommands(std::queue<Command>& commands) {
    if (commands.empty()) return;
    std::cout << "bulk: ";
    while (!commands.empty()) {
        std::cout <<  commands.front();
        if (commands.size() != 1) std::cout << ", ";
        commands.pop();
    }
    std::cout << "\n";
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
    std::queue<Command> queueCommands;
    u_int8_t nestedLevel = 0;
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line == "{") {
            ++nestedLevel;
            if (queueCommands.front().getLevel() == 0) {
                printCommands(queueCommands);    
            }
            continue;
        } else if (line == "}") {
            --nestedLevel;
            if (queueCommands.front().getLevel() == 0 || nestedLevel == 0) {
                printCommands(queueCommands);
            }
        } else {
            queueCommands.push(Command{line, nestedLevel});
        }
        if (queueCommands.size() == countCommands && queueCommands.front().getLevel() == 0) {
            printCommands(queueCommands);
        }
    }
    if (queueCommands.front().getLevel() == 0) {
        printCommands(queueCommands);
    }
    return 0;
}
