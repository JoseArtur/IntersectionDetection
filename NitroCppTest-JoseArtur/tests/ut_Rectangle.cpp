#include <gtest/gtest.h>
#include "shape/rectangle/Rectangle.h"

namespace detector::shape {

    class RectangleTest : public ::testing::Test {
    protected:
        Rectangle rect1{10, 20, 30, 40};
        Rectangle rect2{50, 60, 70, 80};
        Rectangle rect3{30, 40, 50, 60};
    };

    TEST_F(RectangleTest, IntersectsTest) {
        EXPECT_FALSE(rect1.intersects(rect2));
        EXPECT_TRUE(rect1.intersects(rect3));
    }

    TEST_F(RectangleTest, GetIntersectionsTest) {
        const std::shared_ptr<Shape> intersections1 = rect1.getIntersection(rect2);
        EXPECT_TRUE(intersections1->getWidth() == 0 && intersections1->getHeight() == 0);
    }

//
    TEST_F(RectangleTest, GetIntersectionTest) {
        std::shared_ptr<Shape> intersection1 = rect1.getIntersection(rect2);
        EXPECT_TRUE(intersection1->getWidth() == 0 && intersection1->getHeight() == 0);

        std::shared_ptr<Shape> intersection2 = rect1.getIntersection(rect3);
        EXPECT_TRUE(intersection2->getWidth() > 0 && intersection2->getHeight() > 0);
    }

// Test the Rectangle class constructor
    TEST_F(RectangleTest, Constructor) {
        Rectangle rect(10, 20, 30, 40);
        EXPECT_EQ(rect.getX(), 10);
        EXPECT_EQ(rect.getY(), 20);
        EXPECT_EQ(rect.getWidth(), 30);
        EXPECT_EQ(rect.getHeight(), 40);
    }

// Test the Rectangle class intersects method
    TEST_F(RectangleTest, Intersects) {
        Rectangle rect1(10, 20, 30, 40);
        Rectangle rect2(20, 30, 40, 50);
        EXPECT_TRUE(rect1.intersects(rect2));
        Rectangle rect3(100, 200, 300, 400);
        EXPECT_FALSE(rect1.intersects(rect3));
    }
// Test the Rectangle class getIntersection method
    TEST_F(RectangleTest, GetIntersections) {
        Rectangle rect1(10, 20, 30, 40);
        Rectangle rect2(20, 30, 40, 50);
        auto intersections = rect1.getIntersection(rect2);
        EXPECT_EQ(intersections->getX(), 20);
        EXPECT_EQ(intersections->getY(), 30);
        EXPECT_EQ(intersections->getWidth(), 20);
        EXPECT_EQ(intersections->getHeight(), 30);
    }

// Test if two rectangles are equal
    TEST_F(RectangleTest, OperatorEqual) {
        Rectangle rect1(10, 20, 30, 40);
        Rectangle rect2(10, 20, 30, 40);
        EXPECT_TRUE(rect1 == rect2);
        Rectangle rect3(100, 200, 300, 400);
        EXPECT_FALSE(rect1 == rect3);
    }

// Test if one rectangle is less than another when comparing by x, y, width, and height
    TEST_F(RectangleTest, OperatorLessThan) {
        Rectangle rect1(10, 20, 30, 40);
        Rectangle rect2(20, 30, 40, 50);
        EXPECT_TRUE(rect1 < rect2);
        Rectangle rect3(10, 20, 30, 40);
        EXPECT_FALSE(rect1 < rect3);
    }
} // namespace detector::shape