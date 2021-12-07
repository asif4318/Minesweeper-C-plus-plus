cmake_minimum_required(VERSION 3.20)
project(P4_3504C_Asif)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/opt/homebrew/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(P4_3504C_Asif main.cpp minesweeper.h GameState.cpp Toolbox.h Toolbox.cpp Button.cpp Button.h Tile.h Tile.cpp)
target_link_libraries(P4_3504C_Asif sfml-graphics)