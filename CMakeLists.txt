cmake_minimum_required(VERSION 3.6)
project(CA)
set(CXX clang)
set(SRC_FILES
        Defaults.h
        Application/Application.c
        Event/Event.c
        Logic/LogicModel.c
        Logic/LogicView.c
        Logic/LogicController.c
#        Cmd/CmdModel.c
#        Cmd/CmdView.c
#        Cmd/CmdController.c
        View/View.c
        )
add_executable(CA ${SRC_FILES})
target_link_libraries(CA SDL2)
target_compile_options(CA PRIVATE --pedantic -g -O0 -Wall)
