#ifndef VIEW_H
#define VIEW_H

#include <memory>

#include "observ.h"

class Model;

class View : public Observer
{
public:
    View(Model *m);
    inline void setModel(Model *m) { model = std::make_shared<Model>(*m); }
    virtual void update();

private:
    std::shared_ptr<Model> model;
};

#endif // VIEW_H
