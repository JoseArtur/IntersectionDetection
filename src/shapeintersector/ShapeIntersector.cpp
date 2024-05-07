// project include files
#include "intersection/Intersection.h"

#include "ShapeIntersector.h"


namespace detector::shapeintersector {


    void ShapeIntersector::calculate(const std::vector<std::shared_ptr<shape::Shape>> &shapes) {
        m_intersections = calculateAllPairwiseIntersections(shapes);

        bool newIntersectionsFound;
        do {
            std::set<intersection::Intersection> newIntersections = findNewIntersections(shapes);
            newIntersectionsFound = !newIntersections.empty();

            m_intersections.insert(newIntersections.begin(), newIntersections.end());
        } while (newIntersectionsFound);
    }

    std::optional<intersection::Intersection>
    ShapeIntersector::createNewIntersection(const intersection::Intersection &intersection, size_t shapeIndex,
                                            const shape::Shape &shape) {
        if (intersection.shape->intersects(shape)) {
            std::shared_ptr<shape::Shape> intersectionShape = intersection.shape->getIntersection(shape);
            std::set<int> contributingRects = intersection.contributingShapes;
            contributingRects.insert(shapeIndex + 1);
            return intersection::Intersection(std::move(intersectionShape), contributingRects);
        }
        return std::nullopt;
    }

    std::set<intersection::Intersection>
    ShapeIntersector::checkIntersections(const std::set<intersection::Intersection> &intersections,
                                         const std::vector<std::shared_ptr<shape::Shape>> &shape) {
        std::set<intersection::Intersection> newIntersections;
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


    std::set<intersection::Intersection>
    ShapeIntersector::calculateAllPairwiseIntersections(const std::vector<std::shared_ptr<shape::Shape>> &shapes) {
        std::set<intersection::Intersection> intersections;
        for (size_t i = 0; i < shapes.size(); ++i) {
            for (size_t j = i + 1; j < shapes.size(); ++j) {
                if (shapes[i]->intersects(*shapes[j])) {
                    std::shared_ptr<shape::Shape> intersectionShape = shapes[i]->getIntersection(*shapes[j]);
                    if (intersectionShape == nullptr) {
                        continue;
                    }
                    const std::set<int> &contributingShapes = {static_cast<int>(i + 1), static_cast<int>(j + 1)};
                    intersection::Intersection intersection(std::move(intersectionShape), contributingShapes);
                    intersections.insert(intersection);
                }
            }
        }
        return intersections;
    }

    std::set<intersection::Intersection>
    ShapeIntersector::findNewIntersections(const std::vector<std::shared_ptr<shape::Shape>> &shapes) const {
        std::set<intersection::Intersection> newIntersections;
        for (const auto &intersection: m_intersections) {
            for (size_t j = 0; j < shapes.size(); ++j) {
                if (intersection.isPartOfIntersection(j)) {
                    continue;
                }

                auto newIntersection = createIntersectionIfShapesIntersect(intersection, j, *shapes[j]);
                if (newIntersection.has_value() &&
                    m_intersections.find(newIntersection.value()) == m_intersections.end()) {
                    newIntersections.insert(newIntersection.value());
                }
            }
        }
        return newIntersections;
    }

    std::optional<intersection::Intersection>
    ShapeIntersector::createIntersectionIfShapesIntersect(const intersection::Intersection &intersection,
                                                          size_t shapeIndex,
                                                          const shape::Shape &shape) {
        if (intersection.shape->intersects(shape)) {
            std::shared_ptr<shape::Shape> intersectionShape = intersection.shape->getIntersection(shape);
            std::set<int> contributingShapes = intersection.contributingShapes;
            contributingShapes.insert(shapeIndex + 1);
            return intersection::Intersection(std::move(intersectionShape), contributingShapes);
        }
        return std::nullopt;
    }

    std::set<intersection::Intersection> ShapeIntersector::getIntersections() const {

        return m_intersections;
    }

} // namespace detector::shapeintersector