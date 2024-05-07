
#include <vector>
#include <string>
#include <set>
#include "Document.h"
#include "Intersection.h"
#include "ShapeIntersector.h"
#include <memory>
#include <optional>

#pragma once


class BusinessLogic {
public:
    bool loadRectanglesFromJSON(const Document &doc);
    /**
     * Prints the rectangles
     */
    void printRectangles() const;
    /**
     * Print the intersections between the rectangles
     */
    void printIntersections() const;

private:

    // Members
    std::vector<std::unique_ptr<Shape>> shapes;
    ShapeIntersector shapeIntersector;
};

