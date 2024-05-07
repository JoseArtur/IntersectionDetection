#pragma once
// system include files
#include <memory>
#include <optional>
// project include files
#include "document/Document.h"
#include "shape/Shape.h"

namespace detector::loader {

    class Loader {

    public:
        explicit Loader(const std::shared_ptr<document::Document> &document);

        bool load();

        [[nodiscard]] std::optional<std::vector<std::shared_ptr<shape::Shape>>> getShapes() const;


    private:
        const std::shared_ptr<document::Document> &m_doc;
        std::vector<std::shared_ptr<shape::Shape>> shapes;

    };

} // namespace detector::loader
