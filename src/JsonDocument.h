#include "../external/include/rapidjson/document.h"
#include "Document.h"
#include <iostream>
#include <string>
#include <optional>

#pragma once

class JsonDocument : public Document {
public:
    JsonDocument() = default;

    bool load(const std::string &filename) override;

    bool save(const std::string &filename) override;

    bool isObject() const override;

    bool hasArray(const std::string &member) const override;

    bool hasMember(const std::string &member) const override;

    std::string convertToString() const override;

    size_t getArraySize(const std::string &arrayName) const override;

    bool isObjectInArray(const std::string &arrayName, const std::string &member) const override;

    bool isObjectInArray(const std::string &arrayName, size_t index) const override;

    int getIntInArray(const std::string &arrayName, size_t index, const std::string &memberName) const override;

private:
    rapidjson::Document doc;
};