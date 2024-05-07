#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}


bool Rectangle::intersects(const Shape &other) const {
    return !(x + width <= other.getX() || other.getX() + other.getWidth() <= x ||
             y + height <= other.getY() || other.getY() + other.getHeight() <= y);
}

const std::vector<Shape *> Rectangle::getIntersections(const Shape &other) const {
    std::vector<Shape *> intersections;
    if (!intersects(other)) {
        intersections.push_back(new Rectangle(0, 0, 0, 0));
    }

    int newX = std::max(x, other.getX());
    int newY = std::max(y, other.getY());
    int newWidth = std::min(x + width, other.getX() + other.getWidth()) - newX;
    int newHeight = std::min(y + height, other.getY() + other.getHeight()) - newY;
    intersections.push_back(new Rectangle(newX, newY, newWidth, newHeight));
    return intersections;
}

int Rectangle::getX() const {
    return x;
}

int Rectangle::getY() const {
    return y;
}

int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

Shape *Rectangle::getIntersection(const Shape &other) const {
    if (!intersects(other)) {
        return new Rectangle(0, 0, 0, 0);
    }
    int newX = std::max(x, other.getX());
    int newY = std::max(y, other.getY());
    int newWidth = std::min(x + width, other.getX() + other.getWidth()) - newX;
    int newHeight = std::min(y + height, other.getY() + other.getHeight()) - newY;
    return new Rectangle(newX, newY, newWidth, newHeight);
}

std::string Rectangle::toString() const {
    return "Rectangle";
}

bool Rectangle::operator==(const Rectangle &other) const {
        std::cout << "Comparing Rectangles\n";
        return x == other.x && y == other.y && width == other.width && height == other.height;
    }

bool Rectangle::operator<(const Rectangle &other) const {
{
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        if (width != other.width) return width < other.width;
        return height < other.height;
    }
}
