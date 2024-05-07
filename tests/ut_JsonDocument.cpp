#include <fstream>
#include "gtest/gtest.h"
#include "document/json/JsonDocument.h"

namespace detector::document {

    class JsonDocumentTest : public ::testing::Test {

        void SetUp() override {
            std::ofstream jsonFile("json_test.json");
            jsonFile
                    << R"({"rects":[{"x":100,"y":100,"w":250,"h":80},{"x":120,"y":200,"w":250,"h":150},{"x":140,"y":160,"w":250,"h":100},{"x":160,"y":140,"w":350,"h":190}]})";
            jsonFile.close();

        }
    protected:
        JsonDocument doc;
    };

    TEST_F(JsonDocumentTest, LoadTest) {
        ASSERT_FALSE(doc.load("nonexistent_file.json"));
        ASSERT_TRUE(doc.load("json_test.json"));
    }

    TEST_F(JsonDocumentTest, SaveTest) {
        doc.load("json_test.json");
        ASSERT_TRUE(doc.save("output_file.json"));
    }

    TEST_F(JsonDocumentTest, IsObjectTest) {
        doc.load("json_test.json");
        ASSERT_TRUE(doc.isObject());
    }

    TEST_F(JsonDocumentTest, HasArrayTest) {
        doc.load("json_test.json");
        ASSERT_TRUE(doc.hasArray("rects"));
        ASSERT_FALSE(doc.hasArray("nonexistent_array"));
    }

    TEST_F(JsonDocumentTest, HasMemberTest) {
        doc.load("json_test.json");
        ASSERT_TRUE(doc.hasMember("rects"));
        ASSERT_FALSE(doc.hasMember("nonexistent_member"));
    }

    TEST_F(JsonDocumentTest, ConvertToStringTest) {
        doc.load("json_test.json");
        std::string jsonString = doc.convertToString();
        ASSERT_FALSE(jsonString.empty());
    }

    TEST_F(JsonDocumentTest, GetArraySizeTest) {
        doc.load("json_test.json");
        ASSERT_EQ(doc.getArraySize("rects"), 4);
    }

    TEST_F(JsonDocumentTest, GetIntInArrayTest) {
        doc.load("json_test.json");
        ASSERT_EQ(doc.getIntInArray("rects", 0, "x"), 100);
    }

    TEST_F(JsonDocumentTest, MalformedJsonTest) {
        std::ofstream jsonFile("malformed_json_test.json");
        jsonFile
        << R"({"rects":[{"x":100,"y":100,"w":250,"h":80}, {"x":120,"y":200,"w":250,"h":150}, {"x":140,"y":160,"w":250,"h":100}, {"x":160,"y":140,"w":350,"h":190},)";
        jsonFile.close();

        ASSERT_FALSE(doc.load("malformed_json_test.json"));
    }

    TEST_F(JsonDocumentTest, EmptyJsonFileTest) {
        std::ofstream jsonFile("empty_json_test.json");
        jsonFile.close();

        ASSERT_FALSE(doc.load("empty_json_test.json"));
    }


} // namespace detector::document