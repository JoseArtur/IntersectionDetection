#include <gtest/gtest.h>
#include <sstream>
#include "../src/BusinessLogic.h"
#include "../external/include/rapidjson/document.h"
#include "../src/JsonDocument.h"
#include "../src/Rectangle.h"

class RectangleManagerTest : public ::testing::Test {
protected:
    BusinessLogic rectManager;
    JsonDocument jsonParser;
    std::vector<Rectangle> rectangles;
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
TEST_F(RectangleManagerTest, LoadRectanglesFromJSONTest) {
    rapidjson::Document doc;
    JsonDocument jsonParser;
    jsonParser.load("json_test.json");

    EXPECT_TRUE(rectManager.loadRectanglesFromJSON(jsonParser));
    // Add more checks to verify the rectangles were correctly loaded
}

TEST_F(RectangleManagerTest, PrintRectanglesTest) {
    // Redirect std::cout to a stringstream
    std::stringstream ss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    rectManager.printRectangles();

    // Restore std::cout
    std::cout.rdbuf(oldCoutStreamBuf);

    // Check the output
    // Add checks to verify the output is correct
}

TEST_F(RectangleManagerTest, PrintIntersectionsTest) {
    // Redirect std::cout to a stringstream
    std::stringstream ss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    rectManager.printIntersections();

    // Restore std::cout
    std::cout.rdbuf(oldCoutStreamBuf);

    // Check the output
    // Add checks to verify the output is correct
}