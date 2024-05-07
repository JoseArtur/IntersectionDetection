// system include files
#include <iostream>
#include <memory>
#include <optional>
// project include files
#include "shape/rectangle/Rectangle.h"

#include "Loader.h"
namespace detector::loader {


    Loader::Loader(const std::shared_ptr<document::Document> &document) : m_doc(document) {
        load();
    }

    bool Loader::load() {
        std::cout << "Loading shapes..." << std::endl;
        if (!m_doc->isObject() || !m_doc->hasMember("rects") || !m_doc->hasArray("rects")) {
            std::cerr << "Given JSON: " << m_doc->convertToString() << std::endl;
            return false;
        }

        size_t rectsSize = m_doc->getArraySize("rects");
        for (size_t i = 0; i < rectsSize; ++i) {
            if (i >= 10) break;
            if (!m_doc->isObjectInArray("rects", i)) continue;

            // Check if the object has the required properties
            if (!m_doc->hasMemberInArray("rects", i, "x") ||
                !m_doc->hasMemberInArray("rects", i, "y") ||
                !m_doc->hasMemberInArray("rects", i, "w") ||
                !m_doc->hasMemberInArray("rects", i, "h")) {
                std::cerr << "Invalid rectangle in JSON: " << m_doc->convertToString() << std::endl;
                return false;
            }

            auto r = std::make_shared<shape::Rectangle>(
                    m_doc->getIntInArray("rects", i, "x"),
                    m_doc->getIntInArray("rects", i, "y"),
                    m_doc->getIntInArray("rects", i, "w"),
                    m_doc->getIntInArray("rects", i, "h")
            );
            shapes.push_back(std::move(r));
        }
        return true;
    }

    std::optional<std::vector<std::shared_ptr<shape::Shape>>> Loader::getShapes() const {
        if (shapes.empty()) {
            std::cerr << "No shapes loaded." << std::endl;
            return std::nullopt;
        }
        return shapes;
    }
}

// namespace detector::loader