#include <vector>
#include <string>

#pragma once

class Shape {
public:
    virtual bool intersects(const Shape &other) const = 0;

    virtual const std::vector<Shape *> getIntersections(const Shape &other) const = 0;

    virtual const Shape * getIntersection(const Shape &other) const = 0;

    virtual int getX() const = 0;

    virtual int getY() const = 0;

    virtual int getWidth() const = 0;

    virtual int getHeight() const = 0;

    virtual std::string toString() const = 0;
};
