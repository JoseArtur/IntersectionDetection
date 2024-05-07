#pragma once

#include <set>
#include <optional>
#include <memory>

class Intersection;

class ShapeIntersector {
public:
    /**
     * Checks each intersection against all other rectangles
     * @param intersections The intersections to check
     * @return The new intersections
     */
    std::set<Intersection> checkIntersections(const std::set<Intersection> &intersections,
                                              const std::vector<std::unique_ptr<Shape>> &shape) const;

    /**
     * Calculates all intersections between the rectangles
     */
    std::set<Intersection> calculateIntersections(const std::vector<std::unique_ptr<Shape>> &shape
    ) const;

private:

    /**
     * Creates a new intersection from an existing intersection
     * @param intersection The existing intersection
     * @param rectangleIndex The index of the rectangle
     * @return The new intersection
     */
    std::optional<Intersection>
    createNewIntersection(const Intersection &intersection, size_t rectangleIndex, const Shape &shape) const;
};


