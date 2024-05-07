#pragma once
// system include files
#include <set>
#include <memory>
// project include files
#include "shape/Shape.h"

namespace detector::intersection {

    class Intersection {
    public:
        const std::shared_ptr<shape::Shape> shape;
        std::set<int> contributingShapes;

        Intersection(std::shared_ptr<shape::Shape> shape, const std::set<int> &contributingShapes);

        void print() const;

        bool isPartOfIntersection(size_t index) const;

        bool operator==(const Intersection &other) const;

        bool operator!=(const Intersection &other) const;

        bool operator<(const Intersection &other) const;

        bool operator()(const Intersection &lhs, const Intersection &rhs) const;
    };
} // namespace detector::intersection