#include <iostream>
#include "BusinessLogic.h"
#include "JsonDocument.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <JSON_FILE>" << std::endl;
        return 1;
    }

    const char *jsonFilename = argv[1];
    BusinessLogic rectManager;
    JsonDocument jsonParser;

    auto file = jsonParser.load(jsonFilename);

    if (jsonParser.load(jsonFilename)) {
        std::cout << "File has been parsed successfully" << std::endl;
        rectManager.loadRectanglesFromJSON(jsonParser);
    } else {
        std::cerr << "Failed to parse JSON file." << std::endl;
        return 1;
    }

    rectManager.printRectangles();
    rectManager.printIntersections();

    return 0;
}
