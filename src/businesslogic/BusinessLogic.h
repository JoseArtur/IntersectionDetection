#pragma once

// system include files
#include <vector>
#include <string>
#include <set>
#include <memory>
#include <optional>
// project include files
#include "document/Document.h"
#include "intersection/Intersection.h"
#include "shapeintersector/ShapeIntersector.h"
#include "loader/Loader.h"


namespace detector::bussinesslogic {


    class BusinessLogic {
    public:
        /**
         * Constructor
         */
        explicit BusinessLogic(const std::vector<std::shared_ptr<shape::Shape>>& shapes);

        /**
         * Prints the rectangles
         */
        void printRectangles() const;

        /**
         * Print the m_intersections between the rectangles
         */
        void printIntersections() const;

    private:
        // Members
        std::vector<std::shared_ptr<shape::Shape>> shapes;
        shapeintersector::ShapeIntersector shapeIntersector;
    };
} // namespace detector::bussinesslogic