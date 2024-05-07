#include <gtest/gtest.h>
#include "shapeintersector/ShapeIntersector.h"
#include "intersection/Intersection.h"
#include "mocks/MockShape.h"

namespace detector::shapeintersector {


    class ShapeIntersectorTest : public ::testing::Test {
    protected:
        std::unique_ptr<ShapeIntersector> shapeIntersector;
        std::vector<std::shared_ptr<shape::Shape>> shapes;

        void SetUp() override {
            shapeIntersector = std::make_unique<ShapeIntersector>();
            shapes.push_back(std::make_shared<shape::MockShape>());
            shapes.push_back(std::make_shared<shape::MockShape>());
        }
    };


    TEST_F(ShapeIntersectorTest, CheckIntersectionsTest) {
        shapeIntersector->calculate(shapes);
        auto intersections = shapeIntersector->getIntersections();
        auto newIntersections = shapeIntersector->checkIntersections(intersections, shapes);
        ASSERT_EQ(newIntersections.size(), 0);
    }

    TEST_F(ShapeIntersectorTest, CalculateIntersectionsTest) {
        for (const auto &shape: shapes) {
            auto &mockShape = dynamic_cast<shape::MockShape &>(*shape);
            EXPECT_CALL(mockShape, intersects(testing::_))
                    .WillRepeatedly(testing::Return(true));
            EXPECT_CALL(mockShape, getIntersection(testing::_))
                    .WillRepeatedly(testing::Return(std::make_shared<shape::MockShape>()));
        }

        shapeIntersector->calculate(shapes);
        auto intersections = shapeIntersector->getIntersections();
        ASSERT_EQ(intersections.size(), 1);
    }


}