// system include files
#include <vector>
#include <string>
// user include files
#include "Shape.h"

#pragma once

class Rectangle : public Shape {
public:
    int x, y, width, height;

    Rectangle(int x, int y, int width, int height);

    bool intersects(const Shape &other) const override;

    const std::vector<Shape *> getIntersections(const Shape &other) const override;

    Shape *getIntersection(const Shape &other) const override;

    int getX() const override;

    int getY() const override;

    int getWidth() const override;

    int getHeight() const override;

    std::string toString() const;

    bool operator==(const Rectangle &other) const;

    bool operator<(const Rectangle &other) const ;

};
