cmake_minimum_required(VERSION 3.0.0)
project(TTCOpenGL VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
# include(CTest)
# enable_testing()

add_executable(TTCOpenGL.exe src/main.cpp src/game.cpp src/game.hpp src/glad.h src/glad.c)
target_link_libraries(TTCOpenGL.exe glfw OpenGL::GL)
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
