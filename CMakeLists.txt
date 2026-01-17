cmake_minimum_required(VERSION 3.24)
project(ProgettoLaboraatorio12)

set(CMAKE_CXX_STANDARD 23)

# Libreria core
add_library(core
        Note.cpp
        Collezione.cpp
        )

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Eseguibile principale
add_executable(ProgettoLaboraatorio12 main.cpp)
target_link_libraries(ProgettoLaboraatorio12 core)

# GoogleTest
add_subdirectory(C:/Users/Samsung/ProgettoLaboraatorio12/extern/googletest)

enable_testing()

# --- Nuovo blocco: gruppo di sorgenti dei test ---
set(TEST_SOURCES
        tests/NoteTest.cpp
        # qui puoi aggiungere altri file di test in futuro
        )

# Eseguibile dei test
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests core gtest_main)

# Aiuta CLion a indicizzare i file dei test
target_include_directories(runTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include(GoogleTest)
gtest_discover_tests(runTests)
