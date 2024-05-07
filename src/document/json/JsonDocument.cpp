// system include files
#include <fstream>
#include <sstream>
// external library include files
#include "include/rapidjson/writer.h"
// project include files
#include "JsonDocument.h"

namespace detector::document {


    bool JsonDocument::load(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string jsonStr = buffer.str();

        doc.Parse(jsonStr.c_str());
        if (doc.HasParseError()) {
            std::cerr << "Failed to parse JSON: " << filename << "\n"
                      << "Error code: " << doc.GetParseError() << "\n"
                      << "Error offset: " << doc.GetErrorOffset() << "\n";
            return false;
        }

        return true;
    }

    bool JsonDocument::save(const std::string &filename) {
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
        std::string jsonStr = buffer.GetString();

        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }
        file << jsonStr;
        file.close();

        return true;
    }

    bool JsonDocument::isObject() const {
        return doc.IsObject();
    }

    bool JsonDocument::hasArray(const std::string &arrayName) const {
        if (isObject() && hasMember(arrayName)) {
            return doc[arrayName.c_str()].IsArray();
        }
        return false;
    }

    bool JsonDocument::hasMember(const std::string &member) const {
        if (isObject()) {
            return doc.HasMember(member.c_str());
        }
        return false;
    }

    std::string JsonDocument::convertToString() const {
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        doc.Accept(writer);
        return buffer.GetString();
    }

    size_t JsonDocument::getArraySize(const std::string &arrayName) const {
        if (hasMember(arrayName)) {
            return doc[arrayName.c_str()].Size();
        }
        return 0;
    }

    bool JsonDocument::hasMemberInArray(const std::string &arrayName, size_t index, const std::string &member) const {
        if (isObjectInArray(arrayName, index)) {
            return doc[arrayName.c_str()][index].HasMember(member.c_str());
        }
        return false;
    }

    bool JsonDocument::isObjectInArray(const std::string &arrayName, size_t index) const {
        if (hasMember(arrayName)) {
            return doc[arrayName.c_str()][index].IsObject();
        }
        return false;
    }

    int JsonDocument::getIntInArray(const std::string &arrayName, size_t index, const std::string &memberName) const {
        if (!isObjectInArray(arrayName, index)) {
            return 0;
        }

        return doc[arrayName.c_str()][index][memberName.c_str()].GetInt();
    }
} // namespace detector::document