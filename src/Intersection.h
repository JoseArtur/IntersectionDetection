#pragma once

#include <set>
#include "Shape.h"

class Intersection {
public:
    const Shape *shape;
    std::set<int> contributingRects;

    Intersection(const Shape *shape, const std::set<int> &contributingRects);

    void print() const;

    bool isPartOfIntersection(size_t rectangleIndex) const;

    bool operator==(const Intersection &other) const;

    bool operator!=(const Intersection &other) const;

    bool operator<(const Intersection &other) const;

    bool operator()(const Intersection &lhs, const Intersection &rhs) const;
};