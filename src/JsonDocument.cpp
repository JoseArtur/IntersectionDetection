#include "JsonDocument.h"
#include <fstream>
#include <sstream>
#include "../external/include/rapidjson/writer.h"

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
    if (doc.HasMember(arrayName.c_str())) {
        return doc[arrayName.c_str()].IsArray();
    }
    return false;
}

bool JsonDocument::hasMember(const std::string &member) const {
    return doc.HasMember(member.c_str());
}

std::string JsonDocument::convertToString() const {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);
    return buffer.GetString();
}

size_t JsonDocument::getArraySize(const std::string &arrayName) const {
    if (doc.HasMember(arrayName.c_str())) {
        return doc[arrayName.c_str()].Size();
    }
    return 0;
}

bool JsonDocument::isObjectInArray(const std::string &arrayName, const std::string &member) const {
    if (doc.HasMember(arrayName.c_str())) {
        for (rapidjson::SizeType i = 0; i < doc[arrayName.c_str()].Size(); i++) {
            if (doc[arrayName.c_str()][i].IsObject() && doc[arrayName.c_str()][i].HasMember(member.c_str())) {
                return true;
            }
        }
    }
    return false;
}

bool JsonDocument::isObjectInArray(const std::string &arrayName, size_t index) const {
    if (doc.HasMember(arrayName.c_str())) {
        return doc[arrayName.c_str()][index].IsObject();
    }
    return false;
}

int JsonDocument::getIntInArray(const std::string &arrayName, size_t index, const std::string &memberName) const {
    return doc[arrayName.c_str()][index][memberName.c_str()].GetInt();
}