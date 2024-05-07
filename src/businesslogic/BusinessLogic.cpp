// system include files
#include <iostream>
#include <memory>
#include <algorithm>
// project include files
#include "shape/rectangle/Rectangle.h"

#include "businesslogic/BusinessLogic.h"

namespace detector::bussinesslogic {

    BusinessLogic::BusinessLogic(const std::vector<std::shared_ptr<shape::Shape>>& shapes) {
        this->shapes = (shapes);
        shapeIntersector.calculate(shapes);
    }

    void BusinessLogic::printRectangles() const {
        std::cout << "Input:" << std::endl;
        for (int i = 0; i < shapes.size(); i++) {
            std::cout << i + 1 << ": " << shapes[i]->toString() << " at (" << shapes[i]->getX() << ", "
                      << shapes[i]->getY() << "), w="
                      << shapes[i]->getWidth() << ", h=" << shapes[i]->getHeight() << std::endl;
        }
    }

    void BusinessLogic::printIntersections() const {
        std::cout << "Intersections" << std::endl;

        for (const auto &intersection: shapeIntersector.getIntersections()) {
            intersection.print();
        }
    }
} // namespace detector::bussinesslogic
