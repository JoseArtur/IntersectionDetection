#pragma once

// external library include files
#include "include/rapidjson/document.h"
// system include files
#include <iostream>
#include <string>
#include <optional>
// project include files
#include "document/Document.h"

namespace detector::document {
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

        bool isObjectInArray(const std::string &arrayName, size_t index) const override;

        int getIntInArray(const std::string &arrayName, size_t index, const std::string &memberName) const override;

        bool hasMemberInArray(const std::string &arrayName, size_t index, const std::string &member) const override;
    private:
        rapidjson::Document doc;

    };
} // namespace detector::document