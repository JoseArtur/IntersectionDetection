#include <iostream>
#include <memory>
#include "Intersection.h"
#include <algorithm>

#include "BusinessLogic.h"
#include "Rectangle.h"

bool BusinessLogic::loadRectanglesFromJSON(const Document &doc) {

    std::cout << "Loading shapes from JSON..." << std::endl;
    if (!doc.isObject() || !doc.hasMember("rects") || !doc.hasArray("rects")) {
        std::cerr << "Given JSON: " << doc.convertToString() << std::endl;
        return false;
    }

    size_t rectsSize = doc.getArraySize("rects");
    for (size_t i = 0; i < rectsSize; ++i) {
        if (i >= 10) break;
        if (!doc.isObjectInArray("rects", i)) continue;

        auto r = std::make_unique<Rectangle>(
                doc.getIntInArray("rects", i, "x"),
                doc.getIntInArray("rects", i, "y"),
                doc.getIntInArray("rects", i, "w"),
                doc.getIntInArray("rects", i, "h")
        );
        shapes.push_back(std::move(r));
    }
    return true;
}

void BusinessLogic::printRectangles() const {
    std::cout << "Input:" << std::endl;
    for (int i = 0; i < shapes.size(); i++) {
        std::cout << i + 1 << ": " << shapes[i]->toString() << " at (" << shapes[i]->getX() << ", " << shapes[i]->getY() << "), w="
                  << shapes[i]->getWidth() << ", h=" << shapes[i]->getHeight() << std::endl;
    }
}

void BusinessLogic::printIntersections() const {
    std::set<Intersection> intersections = shapeIntersector.calculateIntersections(shapes);
    std::set<Intersection> newIntersections = shapeIntersector.checkIntersections(intersections, shapes);

    intersections.insert(newIntersections.begin(), newIntersections.end());

    std::cout << "Intersections" << std::endl;
    for (const auto &intersection: intersections) {
        intersection.print();
    }
}