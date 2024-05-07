#include "gmock/gmock.h"
#include "shape/Shape.h"

namespace detector::shape {
    class MockShape : public Shape {
    public:
        MOCK_METHOD(bool, intersects, (const Shape &other), (const override));
        MOCK_METHOD(std::shared_ptr<Shape>, getIntersection, (const Shape &other), (const override));
        MOCK_METHOD(int, getX, (), (const override));
        MOCK_METHOD(int, getY, (), (const override));
        MOCK_METHOD(int, getWidth, (), (const override));
        MOCK_METHOD(int, getHeight, (), (const override));
        MOCK_METHOD(std::string, toString, (), (const override));

    };
}
