#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <vector>

class Model;
class Shape;

class Controller
{
public:
    Controller(Model *m);
    inline void setModel(Model *m) { model = std::make_shared<Model>(*m); }
    std::vector<Shape*> getDataFromModel();
    void exportVectorToFile(const char* fileName);
    std::vector<Shape*> importVectorFromFile(const char* fileName);

private:
    std::shared_ptr<Model> model;
};

#endif // CONTROLLER_H
