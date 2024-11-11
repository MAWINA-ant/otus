#ifndef OBSERV_H
#define OBSERV_H

#include <vector>
#include <algorithm>
#include <iostream>

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

class Observable
{
public:
    virtual ~Observable() = default;
    virtual void subscribe(Observer *observer) = 0;
    virtual void unsubscribe(Observer *observer) = 0;
    virtual void notify() = 0;
};

#endif // OBSERV_H