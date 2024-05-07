# Nitro C++ Proficiency Test

## Overview
This console application is written in C++ and designed to process a JSON file containing definitions of rectangles in a 2D space. The program identifies and reports all intersections between the rectangles. The application is designed in a modular and extensible way, allowing for the addition of other shapes and support for different file formats with minimal changes to the existing code.

## Project Structure
The project consists of the following Classes:
- `BusinessLogic.h`: Contains the core logic for processing rectangles and finding intersections.
- `Document.h`: Abstract base class for document handling.
- `JsonDocument.h`: Handles JSON file parsing and validation. An example of extending the `Document.h` base class.
- `Intersection.h`: Represents an intersection between shapes and contains methods to handle intersection logic.
- `Shape.h`: Abstract base class for geometric shapes.
- `Rectangle.h`: Represents a rectangle and contains methods for rectangle properties. An example of extending the `Shape.h` base class.

## Building the Project
To build this project, you will need a C++ compiler that supports C++14 or later. The following steps will guide you through the compilation process:

1. Navigate to the root directory of the project.
2. Use the following command to compile the project:

````bash
g++ -std=c++14 -o RectangleIntersections main.cpp BusinessLogic.cpp Intersection.cpp JsonDocument.cpp Rectangle.cpp
````
3. This will generate an executable named `detect_interesections`.

## Running the Application
To run the application, use the following command:

./detect_interesections <path_to_json_file>

Replace `<path_to_json_file>` with the path to your JSON file containing the rectangle definitions.

## Testing
Unit tests are provided to ensure the correctness of the application. To run the tests, navigate to the test directory and follow the instructions in the test README.

## Dependencies
This project uses the following open-source libraries:
- rapidjson/json for JSON parsing.
- googletest/googletest for unit testing.
