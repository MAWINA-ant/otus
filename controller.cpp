#include "controller.h"
#include "model.h"

Controller::Controller(Model *m)
{
    model = std::make_shared<Model>(*m);
}

std::vector<Shape *> Controller::getDataFromModel()
{
    return model->getData();
}
