#include <fstream>
#include "gtest/gtest.h"
#include "loader/Loader.h"
#include "document/json/JsonDocument.h"

namespace detector::loader {
    class LoaderTest : public ::testing::Test {
    protected:
        std::shared_ptr<document::JsonDocument> doc;
        std::unique_ptr<Loader> loader;

        void SetUp() override {
            doc = std::make_shared<document::JsonDocument>();
        }
    };

    TEST_F(LoaderTest, LoadTest) {
        std::ofstream jsonFile("json_test.json");
        jsonFile
                << R"({"rects":[{"x":100,"y":100,"w":250,"h":80},{"x":120,"y":200,"w":250,"h":150},{"x":140,"y":160,"w":250,"h":100},{"x":160,"y":140,"w":350,"h":190}]})";
        jsonFile.close();
        doc->load("json_test.json");
        Loader loader(doc);

        ASSERT_TRUE(loader.load());

    }

    TEST_F(LoaderTest, nonExistentFileTest) {
        doc->load("nonexistent_file.json");
        Loader loader(doc);
        ASSERT_FALSE(loader.load());
    }

    TEST_F(LoaderTest, GetShapesTest) {
        std::ofstream jsonFile("json_test.json");
        jsonFile
                << R"({"rects":[{"x":100,"y":100,"w":250,"h":80},{"x":120,"y":200,"w":250,"h":150},{"x":140,"y":160,"w":250,"h":100},{"x":160,"y":140,"w":350,"h":190}]})";
        jsonFile.close();
        doc->load("json_test.json");
        Loader loader(doc);
        auto shapes = loader.getShapes();
        ASSERT_EQ(shapes.has_value(), true);
        ASSERT_EQ(shapes.value().size(), 4);
    }

    TEST_F(LoaderTest, GetShapesEmptyTest) {
        std::ofstream jsonFile("json_test.json");
        jsonFile << R"({"rects":[]})";
        jsonFile.close();
        doc->load("json_test.json");
        Loader loader(doc);
        auto shapes = loader.getShapes();
        ASSERT_EQ(shapes.has_value(), false);
    }

    TEST_F(LoaderTest, GetShapesInvalidTest) {

        std::ofstream jsonFile("json_test.json");
        jsonFile
                << R"({"rects":[{"z":100,"y":100,"w":250,"h":80},{"x":120,"y":200,"w":250,"h":150},{"x":140,"y":160,"w":250,"h":100},{"x":160,"y":140,"w":350,"h":190}]})";
        jsonFile.close();
        doc->load("json_test.json");
        Loader loader(doc);
        auto shapes = loader.getShapes();
        ASSERT_EQ(shapes.has_value(), false);
        ASSERT_FALSE(loader.load());
    }

    TEST_F(LoaderTest, LoadAtLeastTenRectanglesTest) {
    std::ofstream jsonFile("json_test.json");
    jsonFile << R"({
        "rects":[
            {"x":100,"y":100,"w":250,"h":80},
            {"x":120,"y":200,"w":250,"h":150},
            {"x":140,"y":160,"w":250,"h":100},
            {"x":160,"y":140,"w":350,"h":190},
            {"x":180,"y":120,"w":450,"h":280},
            {"x":200,"y":100,"w":550,"h":380},
            {"x":220,"y":80,"w":650,"h":480},
            {"x":240,"y":60,"w":750,"h":580},
            {"x":260,"y":40,"w":850,"h":680},
            {"x":280,"y":20,"w":950,"h":780},
            {"x":300,"y":0,"w":1050,"h":880}
        ]
    })";
    jsonFile.close();
    doc->load("json_test.json");
    Loader loader(doc);
    auto shapes = loader.getShapes();
    ASSERT_EQ(shapes.has_value(), true);
    ASSERT_EQ(shapes.value().size(), 10);
}
} // namespace detector::loader