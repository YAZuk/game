cmake_minimum_required(VERSION 3.26)
project(game)

set(CMAKE_CXX_STANDARD 23)

#find_package(OpenGL REQUIRED)


include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT)

#message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

#find_package(GLFW3 REQUIRED)
#message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

#target_link_libraries(${PROJECT_NAME} ${LIBS})

add_executable(game main.cpp
        Unit.cpp
        Unit.h
        Transport.cpp
        Transport.h
        Archer.cpp
        Archer.h
)

target_link_libraries(game ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARY})