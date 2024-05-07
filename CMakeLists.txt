cmake_minimum_required(VERSION 3.22)

project(IntersectionDetection)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/external
    ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/tests

)

find_package(GTest REQUIRED)

include(GoogleTest)
include(CTest)

# Enable testing
enable_testing()

add_executable(detect_interesections
    src/main.cpp
    src/intersection/Intersection.cpp
    src/businesslogic/BusinessLogic.cpp
    src/shape/rectangle/Rectangle.cpp
    src/shapeintersector/ShapeIntersector.cpp
    src/document/json/JsonDocument.cpp
        src/loader/Loader.cpp
)

target_include_directories(detect_interesections PRIVATE src)

add_executable(run_ut_rectangle
    src/shape/rectangle/Rectangle.cpp
    tests/ut_Rectangle.cpp
)
add_executable(run_ut_jsondocument
        src/document/json/JsonDocument.cpp
    tests/ut_JsonDocument.cpp
)

add_executable(run_ut_loader
        src/loader/Loader.cpp
        src/document/json/JsonDocument.cpp
        src/shape/rectangle/Rectangle.cpp
        tests/ut_Loader.cpp
)
add_executable(run_ut_shapeintersector
    src/shapeintersector/ShapeIntersector.cpp
        src/intersection/Intersection.cpp
    tests/ut_ShapeIntersector.cpp
)

target_link_libraries(run_ut_rectangle GTest::gtest_main pthread)
target_link_libraries(run_ut_jsondocument GTest::gtest_main pthread)
target_link_libraries(run_ut_shapeintersector GTest::gtest_main GTest::gmock_main pthread)
target_link_libraries(run_ut_loader GTest::gtest_main pthread)