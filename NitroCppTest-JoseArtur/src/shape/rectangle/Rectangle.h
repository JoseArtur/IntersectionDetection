#pragma once

// system include files
#include <vector>
#include <string>
// user include files
#include "shape/Shape.h"

namespace detector::shape {
    class Rectangle : public Shape {
    public:
        int x, y, width, height;

        Rectangle(int x, int y, int width, int height);

        [[nodiscard]] bool intersects(const Shape &other) const override;

        [[nodiscard]] std::shared_ptr<Shape> getIntersection(const Shape &other) const override;

        [[nodiscard]] int getX() const override;

        [[nodiscard]] int getY() const override;

        [[nodiscard]] int getWidth() const override;

        [[nodiscard]] int getHeight() const override;

        [[nodiscard]] std::string toString() const override;

        bool operator==(const Rectangle &other) const;

        bool operator<(const Rectangle &other) const;

    };
} // namespace detector::shape