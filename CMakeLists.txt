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


set(TEST_SOURCES
        tests/NoteTest.cpp
        )


add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests core gtest_main)


target_include_directories(runTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include(GoogleTest)
gtest_discover_tests(runTests)
