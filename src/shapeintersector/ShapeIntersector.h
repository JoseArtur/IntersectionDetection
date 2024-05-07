#pragma once

#include <set>
#include <optional>
#include <memory>
#include "shape/Shape.h"
#include "intersection/Intersection.h"
/**
 * The shape intersector class
 @brief
 */
namespace detector::shapeintersector {

    class ShapeIntersector {
    public:

        void calculate(const std::vector<std::shared_ptr<shape::Shape>> &shapes);

        [[nodiscard]] std::set<intersection::Intersection> getIntersections() const;

/**
 * Checks each intersection against all other rectangles
 * @param intersections The m_intersections to check
 * @return The new m_intersections
 */
        [[nodiscard]] static std::set<intersection::Intersection>
        checkIntersections(const std::set<intersection::Intersection> &intersections,
                           const std::vector<std::shared_ptr<shape::Shape>> &shape) ;

    private:
        /**
         * Creates a new intersection from an existing intersection
         * @param intersection The existing intersection
         * @param index The index of the shape
         * @return The new intersection
         */
        [[nodiscard]] static std::optional<intersection::Intersection>
        createNewIntersection(const intersection::Intersection &intersection, size_t index,
                              const shape::Shape &shape) ;


        [[nodiscard]] static std::set<intersection::Intersection>
        calculateAllPairwiseIntersections(const std::vector<std::shared_ptr<shape::Shape>> &shapes) ;
        [[nodiscard]] static std::optional<intersection::Intersection>
        createIntersectionIfShapesIntersect(const intersection::Intersection &intersection, size_t shapeIndex,
                                            const shape::Shape &shape) ;
        [[nodiscard]] std::set<intersection::Intersection>
        findNewIntersections(const std::vector<std::shared_ptr<shape::Shape>> &shapes) const;
        std::set<intersection::Intersection> m_intersections;

    };
} // namespace detector::shapeintersector


