#include <gtest/gtest.h>
#include "../src/Rectangle.h"

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
    std::vector<Shape*> intersections1 = rect1.getIntersections(rect2);
    EXPECT_TRUE(intersections1[0]->getWidth() == 0 && intersections1[0]->getHeight() == 0);

    std::vector<Shape*> intersections2 = rect1.getIntersections(rect3);
    EXPECT_TRUE(intersections2[0]->getWidth() > 0 && intersections2[0]->getHeight() > 0);
}

TEST_F(RectangleTest, GetIntersectionTest) {
    Shape* intersection1 = rect1.getIntersection(rect2);
    EXPECT_TRUE(intersection1->getWidth() == 0 && intersection1->getHeight() == 0);

    Shape* intersection2 = rect1.getIntersection(rect3);
    EXPECT_TRUE(intersection2->getWidth() > 0 && intersection2->getHeight() > 0);
}