#include <iostream>
#include <fstream>

#include "logger.h"

void ObservableLogger::subscribe(Observer *observer) {
    observers.push_back(observer);
}

void ObservableLogger::unsubscribe(Observer *observer) {
    observers.erase(std::find(observers.begin(), observers.end(), observer));
}

void ObservableLogger::notify() {
    auto size = observers.size();
    for (auto i = 0; i < size; ++i) {
        observers[i]->update();
    }
}

void CoutLogger::update() {
    std::cout << "bulk: ";
    while (!data.empty()) {
        std::cout << *data.front();
        if (data.size() != 1) {
            std::cout << ", ";
        }
        data.pop();
    }
    std::cout << "\n";
}

void FileLogger::update() {
    std::string fileName = "bulk" + std::to_string(data.front()->getTime());
    std::ofstream out;
    out.open(fileName);
    out << "bulk: ";
    while (!data.empty()) {
        out << *data.front();
        if (data.size() != 1) {
            out << ", ";
        }
        data.pop();
    }
}