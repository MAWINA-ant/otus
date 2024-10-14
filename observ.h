#ifndef OBSERV_H
#define OBSERV_H

#include <vector>
#include <iostream>

class Observer
{
public:
    virtual void update() = 0;
};

class Observable
{
public:
    void addObserver(Observer *observer)
    {
        std::cout << "addObserver()\n";
        _observers.push_back(observer);
    }

    void notifyUpdate()
    {
        int size = _observers.size();
        std::cout << "nitifyUpdate(), observers size = " << size << "\n";
        for (int i = 0; i < size; i++)
        {
            _observers[i]->update();
        }
    }
private:
    std::vector<Observer*> _observers;
};

#endif // OBSERV_H
