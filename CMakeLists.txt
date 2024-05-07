# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.22)

# Project's name
project(YourProjectName)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
enable_testing()

# Add the executable for the main application
add_executable(detect_interesections
        src/main.cpp
        src/Intersection.cpp
        src/BusinessLogic.cpp
        src/Rectangle.cpp
        src/ShapeIntersector.cpp
        src/JsonDocument.cpp)
# Add more source files as needed
include(GoogleTest)
include_directories(${GTEST_INCLUDE_DIRS})

# Include directories for the main application
target_include_directories(detect_interesections PRIVATE src)
include_directories(external/googletest/include)
include(CTest)

# Locate the Google Test library
find_package(GTest REQUIRED)
# Add the executable for the test suite
add_executable(run_opt_test src/Intersection.cpp src/BusinessLogic.cpp  src/ShapeIntersector.cpp src/Rectangle.cpp tests/tests.cpp
        src/JsonDocument.cpp)
add_executable(run_opt_test2 src/Intersection.cpp src/BusinessLogic.cpp src/ShapeIntersector.cpp src/Rectangle.cpp tests/ut_RectangleManager.cpp
        src/JsonDocument.cpp)
add_executable(run_ut_rectangle src/Rectangle.cpp tests/ut_Rectangle.cpp)
# Link the Google Test main library
target_link_libraries(run_opt_test GTest::gtest_main pthread)
target_link_libraries(run_opt_test2 GTest::gtest_main pthread)
target_link_libraries(run_ut_rectangle GTest::gtest_main pthread)

