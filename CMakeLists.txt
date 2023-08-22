cmake_minimum_required(VERSION 3.26)
project(game)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)

#find_package(GLM REQUIRED)
#message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

#find_package(GLFW3 REQUIRED)
#message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

#target_link_libraries(${PROJECT_NAME} ${LIBS})

add_executable(game main.cpp
        Unit.cpp
        Unit.h
        Transport.cpp
        Transport.h
)

