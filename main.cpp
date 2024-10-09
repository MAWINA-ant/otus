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

Model* createNewDoc(std::vector<Shape*> v) {
    return new Model(v);
}

bool removeShape(Shape* shape) {
    return true;
}

void importModelFromFile(const char* fileName, Controller con) {
    std::vector<Shape*> v;
    con.setModel(createNewDoc(v));
}

void exportModelToFile(const char* fileName, Controller con) {
    auto v = con;
}

int main() {   

    return 0;
}
