#include "Intersection.h"
#include <iostream>

Intersection::Intersection(const Shape *shape, const std::set<int> &contributingRects)
        : shape(shape), contributingRects(contributingRects) {}

void Intersection::print() const {
    std::cout << "Between " << shape->toString() << "s ";
    for (auto it = contributingRects.begin(); it != contributingRects.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != contributingRects.end()) {
            std::cout << ", ";
        }
    }
    std::cout << " at (" << shape->getX() << "," << shape->getY() << "), w=" << shape->getWidth() << ", h="
              << shape->getHeight() << ".\n";
}

bool Intersection::isPartOfIntersection(size_t rectangleIndex) const {
    return contributingRects.find(rectangleIndex + 1) != contributingRects.end();
}

bool Intersection::operator==(const Intersection &other) const {
    return shape->getY() == other.shape->getY() && shape->getX() == other.shape->getX() &&
           shape->getWidth() == other.shape->getWidth() && shape->getHeight() == other.shape->getHeight() &&
           contributingRects == other.contributingRects;
}

bool Intersection::operator!=(const Intersection &other) const {
    return !(*this == other);
}

bool Intersection::operator<(const Intersection &other) const {
    if (contributingRects.size() != other.contributingRects.size())
        return contributingRects.size() < other.contributingRects.size();

    if (shape->getX() != other.shape->getX()) return shape->getX() < other.shape->getX();
    if (shape->getY() != other.shape->getY()) return shape->getY() < other.shape->getY();
    if (shape->getWidth() != other.shape->getWidth()) return shape->getWidth() < other.shape->getWidth();
    if (shape->getHeight() != other.shape->getHeight()) return shape->getHeight() < other.shape->getHeight();
    return false;
}

bool Intersection::operator()(const Intersection &lhs, const Intersection &rhs) const {
    return lhs < rhs;
}