#ifndef LOGGER_H
#define LOGGER_H

#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>
#include <fstream>

#include "observ.h"
#include "command.h"

class ObservableLogger : public Observable
{

public:
    virtual void subscribe(Observer *observer);
    virtual void unsubscribe(Observer *observer);
    virtual void notify();

private:
    std::vector<Observer*> observers;
};

class LoggerData {

public:
    void appendData(Command* value) {
        data.push(value);
    }

protected:
    std::queue<Command*> data;
};

class CoutLogger : public Observer, public LoggerData
{

public:
    void update() override;
};

class FileLogger : public Observer, public LoggerData
{
    
public:
    void update() override;
};

#endif