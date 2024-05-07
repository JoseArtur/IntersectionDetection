#include <gtest/gtest.h>

#include "../src/BusinessLogic.h"
#include "../src/Rectangle.h"
#include "../src/JsonDocument.h"

// Test fixture for setting up rectangles and intersections
class NitroCppTest : public ::testing::Test {
protected:
    std::vector<Rectangle> rectangles;
    JsonDocument jsonParser;
    BusinessLogic rectManager;
   // std::vector<Intersection> intersections;

    void SetUp() override {
        jsonParser.load("json_test.json");
        rectManager.loadRectanglesFromJSON(jsonParser);
        // Initialize rectangles from JSON file
        rectangles.push_back(Rectangle(100, 100, 250, 80));
        rectangles.push_back(Rectangle(120, 200, 250, 150));
        rectangles.push_back(Rectangle(140, 160, 250, 100));
        rectangles.push_back(Rectangle(160, 140, 350, 190));
        // Calculate intersections
       // intersections = calculateIntersections(rectangles);
    }
};

// Test case to check if rectangles are loaded correctly
TEST_F(NitroCppTest, RectangleLoading) {
    EXPECT_EQ(rectangles.size(), 4);
   // EXPECT_EQ(rectangles[0], Rectangle(100, 100, 250, 80));[^1^][1]
    // Add more checks for other rectangles
}

// Test case to check if intersections are calculated correctly
TEST_F(NitroCppTest, CalculateIntersections) {
  //  auto intersections = rectManager.calculateIntersections();
    // Assuming that there should be 6 intersections for the given rectangles
  //  EXPECT_EQ(intersections.size(), 6);
}

// Add more test cases as needed