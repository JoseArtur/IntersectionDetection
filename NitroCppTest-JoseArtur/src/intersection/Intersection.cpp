// system include files
#include <iostream>
#include <utility>

#include "Intersection.h"

namespace detector::intersection {

    Intersection::Intersection(std::shared_ptr<shape::Shape> shape, const std::set<int> &contributingShapes)
            : shape(std::move((shape))), contributingShapes(contributingShapes) {}

    void Intersection::print() const {
        std::cout << "Between " << shape->toString() << "s ";
        for (auto it = contributingShapes.begin(); it != contributingShapes.end(); ++it) {
            std::cout << *it;
            if (std::next(it) != contributingShapes.end()) {
                std::cout << ", ";
            }
        }
        std::cout << " at (" << shape->getX() << "," << shape->getY() << "), w=" << shape->getWidth() << ", h="
                  << shape->getHeight() << ".\n";
    }

    bool Intersection::isPartOfIntersection(size_t index) const {
        return contributingShapes.find(index + 1) != contributingShapes.end();
    }

    bool Intersection::operator==(const Intersection &other) const {
        return shape->getY() == other.shape->getY() && shape->getX() == other.shape->getX() &&
               shape->getWidth() == other.shape->getWidth() && shape->getHeight() == other.shape->getHeight() &&
               contributingShapes == other.contributingShapes;
    }

    bool Intersection::operator!=(const Intersection &other) const {
        return !(*this == other);
    }

    bool Intersection::operator<(const Intersection &other) const {
        if (contributingShapes.size() != other.contributingShapes.size())
            return contributingShapes.size() < other.contributingShapes.size();

        if (shape->getX() != other.shape->getX()) return shape->getX() < other.shape->getX();
        if (shape->getY() != other.shape->getY()) return shape->getY() < other.shape->getY();
        if (shape->getWidth() != other.shape->getWidth()) return shape->getWidth() < other.shape->getWidth();
        if (shape->getHeight() != other.shape->getHeight()) return shape->getHeight() < other.shape->getHeight();
        return false;
    }

    bool Intersection::operator()(const Intersection &lhs, const Intersection &rhs) const {
        return lhs < rhs;
    }
} // namespace detector::intersection
