
#include <string>

#pragma once

class Document {
public:
    virtual ~Document() {}

    virtual bool load(const std::string &filename) = 0;

    virtual bool save(const std::string &filename) = 0;

    virtual bool isObject() const = 0;

    virtual bool hasArray(const std::string &member) const = 0;

    virtual bool hasMember(const std::string &member) const = 0;

    virtual size_t getArraySize(const std::string &arrayName) const = 0;

    virtual bool isObjectInArray(const std::string &arrayName, const std::string &member) const = 0;

    virtual bool isObjectInArray(const std::string &arrayName, size_t index) const = 0;

    virtual int getIntInArray(const std::string &arrayName, size_t index, const std::string &memberName) const = 0;

    virtual std::string convertToString() const = 0;
};


