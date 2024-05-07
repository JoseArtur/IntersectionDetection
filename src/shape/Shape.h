#pragma once
// system include files
#include <vector>
#include <string>
#include <memory>

namespace detector::shape {
class Shape {
public:
    virtual bool intersects(const Shape &other) const = 0;

    virtual std::shared_ptr<Shape> getIntersection(const Shape &other) const = 0;

    virtual int getX() const = 0;

    virtual int getY() const = 0;

    virtual int getWidth() const = 0;

    virtual int getHeight() const = 0;

    virtual std::string toString() const = 0;
};
} // namespace detector::shape