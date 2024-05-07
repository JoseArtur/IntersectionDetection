#include "Intersection.h"
#include "ShapeIntersector.h"


std::optional<Intersection>
ShapeIntersector::createNewIntersection(const Intersection &intersection, size_t rectangleIndex,
                                        const Shape &shape) const {
    if (intersection.shape->intersects(shape)) {
        const Shape *intersectionRect = intersection.shape->getIntersection(shape);
        std::set<int> contributingRects = intersection.contributingRects;
        contributingRects.insert(rectangleIndex + 1);
        return Intersection(intersectionRect, contributingRects);
    }
    return std::nullopt;
}

std::set<Intersection> ShapeIntersector::checkIntersections(const std::set<Intersection> &intersections,
                                                            const std::vector<std::unique_ptr<Shape>> &shape) const {
    std::set<Intersection> newIntersections;
    for (auto &intersection: intersections) {
        for (size_t j = 0; j < shape.size(); ++j) {
            if (intersection.isPartOfIntersection(j)) {
                continue;
            }

            auto newIntersection = createNewIntersection(intersection, j, *shape[j]);
            if (newIntersection.has_value() && intersections.find(newIntersection.value()) == intersections.end()) {
                newIntersections.insert(newIntersection.value());
            }
        }
    }
    return newIntersections;
}

std::set<Intersection> ShapeIntersector::calculateIntersections(const std::vector<std::unique_ptr<Shape>> &shape
) const {
    std::set<Intersection> intersections;

    for (size_t i = 0; i < shape.size(); ++i) {
        for (size_t j = i + 1; j < shape.size(); ++j) {
            if (shape[i]->intersects(*shape[j])) {
                const Shape *intersectionShape = shape[i]->getIntersection(*shape[j]);
                if (intersectionShape == nullptr) {
                    continue;
                }
                const std::set<int> &contributingRects = {static_cast<int>(i + 1), static_cast<int>(j + 1)};
                Intersection intersection(intersectionShape, contributingRects);
                intersections.insert(intersection);
            }
        }
    }
    return intersections;
}