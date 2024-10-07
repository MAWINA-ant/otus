#ifndef VIEW_H
#define VIEW_H

#include "observ.h"

class Model;

class View : public Observer
{
public:
    View(Model *m);
    virtual void update();

private:
    Model *model;
};

#endif // VIEW_H
