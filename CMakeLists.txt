cmake_minimum_required(VERSION 3.24)
project(ProgettoLaboraatorio12)

set(CMAKE_CXX_STANDARD 23)

add_library(core
        Note.cpp
        Collezione.cpp
        )

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ProgettoLaboraatorio12 main.cpp)
target_link_libraries(ProgettoLaboraatorio12 core)


add_subdirectory(C:/Users/Samsung/ProgettoLaboraatorio12/extern/googletest)

enable_testing()

add_executable(runTests
        tests/NoteTest.cpp
        )
target_link_libraries(runTests core gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)
