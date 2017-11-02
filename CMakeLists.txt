cmake_minimum_required(VERSION 3.6)
project(CA)
set(CXX clang)
set(SRC_FILES
        Application.c
        Event/Event.c
        Models/LogicModel.c
        Models/CmdModel.c
        Views/LogicView.c
        Views/CmdView.c
        Views/View.c
        Controllers/LogicController.c
        Controllers/CmdController.c)
add_executable(CA ${SRC_FILES})
target_link_libraries(CA SDL2)
target_compile_options(CA PRIVATE --pedantic -g -O2 -Wall)
