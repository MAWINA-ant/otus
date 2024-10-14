#include "model.h"
#include "observ.h"

#include <algorithm>

void Line::draw() {
    std::cout << "It is Line\n";
}

void Triangle::draw() {
    std::cout << "It is Triangle\n";
}

void Circle::draw() {
    std::cout << "It is Circle\n";
}

void Model::appendShape(Shape *sh)
{
    data.push_back(sh);
    notifyUpdate();
}

void Model::removeShape(Shape *sh)
{
    auto it = std::find(data.begin(), data.end(), sh);
    data.erase(it, it + 1);
    notifyUpdate();
}
