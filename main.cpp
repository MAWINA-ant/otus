#include "command.h"
#include "logger.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not anought arguments! Minimum 2 (for example ./bulk 3)\n";
        return 1;
    }
    auto maxCommands = std::atoi(argv[1]); 
    if (!maxCommands) {
        std::cout << "Second argument should be a number\n";
        return 1;
    }
    uint8_t nestedLevel {0};
    size_t countCommands {0};
    ObservableLogger observableLogger;
    CoutLogger coutLogger;
    FileLogger fileLogger;
    observableLogger.subscribe(&coutLogger);
    observableLogger.subscribe(&fileLogger);
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line == "{") {
            ++nestedLevel;
        } else if (line == "}") {
            --nestedLevel;
        } else {
            auto command = new Command(line, std::time(nullptr), nestedLevel);
            coutLogger.appendData(command);
            fileLogger.appendData(command);
            ++countCommands;
        }
        if ((line == "{" && nestedLevel == 1 && countCommands != 0) ||
            (nestedLevel == 0 && countCommands >= 3)) {
                observableLogger.notify();
                countCommands = 0;
            }
    }
    if (nestedLevel == 0 && countCommands != 0) {
        observableLogger.notify();
    }
    return 0;
}
