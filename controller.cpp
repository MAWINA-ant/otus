#include "controller.h"
#include "model.h"

#include <filesystem>
#include <iostream>

Controller::Controller(Model *m)
{
    model = std::make_shared<Model>(*m);
}

std::vector<Shape *> Controller::getDataFromModel()
{
    return model->getData();
}

void Controller::exportVectorToFile(const char *fileName) {
    std::cout << "import vectror to file " << fileName << "\n";
}

std::vector<Shape*> Controller::importVectorFromFile(const char *fileName) {
    std::cout << "export vectror from file " << fileName << "\n";
    std::vector<Shape*> v;
    v.push_back(new Triangle());
    return v;
}
