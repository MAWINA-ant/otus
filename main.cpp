#include <iostream>
#include <memory>

#include "model.h"
#include "view.h"
#include "controller.h"

Model* importModelFromFile(const char* fileName) {

}

void exportModelToFile(const char* fileName, Controller con) {

}

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

bool removeShape(Shape* shape) {
    return true;
}

Model* createNewDoc() {

}

int main() {   

    return 0;
}
