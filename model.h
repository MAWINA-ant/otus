#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <memory>

#include "observ.h"

enum class ShapeType {
    Line = 1,
    Triangle,
    Circle
};

class Shape {

public:
    Shape() {}
    virtual ~Shape() {}
    virtual void draw() = 0;

private:
};

class Line : public Shape {

public:
    void draw() override;
};

class Triangle : public Shape {

public:
    void draw() override;
};

class Circle : public Shape {

public:
    void draw() override;
};

class Model : public Observable
{

public:
    Model(std::vector<Shape*> v) : data{v} {
    }

    void appendShape();
    void removeShape(Shape* sh);
    std::vector<Shape*> getData() { return data; }

private:
    std::vector<Shape*> data;
};

#endif // MODEL_H
