#include "model.h"
#include "observ.h"

void Line::draw() {
    std::cout << "It is Line\n";
}

void Triangle::draw() {
    std::cout << "It is Triangle\n";
}

void Circle::draw() {
    std::cout << "It is Circle\n";
}

void Model::appendShape()
{
    notifyUpdate();
}

void Model::removeShape(Shape *sh)
{
    notifyUpdate();
}
