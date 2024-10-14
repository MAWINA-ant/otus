#include <iostream>
#include <memory>

#include "model.h"
#include "view.h"
#include "controller.h"

Shape* createShape(ShapeType sType) {
    switch (sType) {
    case ShapeType::Line: {
        return new Line();
    }
    case ShapeType::Triangle: {
        return new Triangle();
    }
    case ShapeType::Circle: {
        return new Circle();
    }
    }
    return nullptr;
}

Model* createNewDoc(std::vector<Shape*> v = {}) {
    return new Model(v);
}

bool removeShape(Shape* shape) {
    return true;
}

Model* importModelFromFile(const char* fileName, Controller con) {
    auto v = con.importVectorFromFile(fileName);
    Model *m = createNewDoc(v);
    con.setModel(m);
    return m;
}

void exportModelToFile(const char* fileName, Controller con) {
    con.exportVectorToFile(fileName);
}

int main() {

    auto model = createNewDoc();
    auto view = View(std::move(model));
    auto controller = Controller(model);
    auto line = createShape(ShapeType::Line);
    auto triangle = createShape(ShapeType::Triangle);
    auto circle = createShape(ShapeType::Circle);
    model->appendShape(line);
    model->appendShape(triangle);
    model->appendShape(circle);
    model->removeShape(triangle);
    exportModelToFile("some/file/data", controller);
    auto model2 = importModelFromFile("some/file/data", controller);
    view.setModel(model2);
    return 0;
}
