#ifndef CONTROLLER_H
#define CONTROLLER_H

class Model;

class Controller
{
public:
    Controller(Model *m);

private:
    Model *model;
};

#endif // CONTROLLER_H
