// system include files
#include <iostream>
// project include files
#include "businesslogic/BusinessLogic.h"
#include "document/json/JsonDocument.h"

void printHelp() {
    std::cout << "Usage: ./program <FILENAME>\n"
              << "Arguments:\n"
              << "  <FILE>    The JSON file to parse.\n"
              << "Options:\n"
              << "  --help    Show this help message and exit.\n";
}

int main(int argc, char *argv[]) {
    using namespace detector;
       if (argc != 2 || std::string(argv[1]) == "--help") {
        printHelp();
        return 1;
    }

    const char *filename = argv[1];
    std::shared_ptr<document::JsonDocument> doc = std::make_shared<document::JsonDocument>();
    std::shared_ptr<bussinesslogic::BusinessLogic> businessLogic;

    if (doc->load(filename)) {
        std::cout << "File has been parsed successfully" << std::endl;
        loader::Loader loader(doc);
        businessLogic = std::make_shared<bussinesslogic::BusinessLogic>(loader.getShapes().value());

    } else {
        std::cerr << "Failed to parse JSON file." << std::endl;
        return 1;
    }

    businessLogic->printRectangles();
    businessLogic->printIntersections();

    return 0;
}
