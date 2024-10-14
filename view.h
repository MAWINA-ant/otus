#ifndef VIEW_H
#define VIEW_H

#include <memory>

#include "observ.h"

class Model;

class View : public Observer
{
public:
    View(Model *m);
    void setModel(Model *m);
    virtual void update() override;

private:
    Model *model;
};

#endif // VIEW_H
