cmake_minimum_required(VERSION 3.26)
project(game)

set(CMAKE_CXX_STANDARD 17)

#find_package(OpenGL REQUIRED)


#find_package(OpenGL REQUIRED)
#find_package(FREEGLUT REQUIRED)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)
#find_package(DWMAPI REQUIRED)

#set(BUILD_SHARED_LIBS OFF)

#SET(GLUT_INCLUDE_DIR "c:\\Program Files\\JetBrains\\CLion 2023.2\\bin\\mingw\\x86_64-w64-mingw32\\")
#SET(GLUT_LIBRARY "c:\\Program Files (x86)\\freeglut\\bin\\libfreeglut.dll")
#SET(GLUT_LIBRARY "c:\\Program Files (x86)\\freeglut\\lib\\libfreeglut_static.a")
#set_target_properties(freeglut_static PROPERTIES LINK_SEARCH_END_STATIC 1)
#set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
#set_target_properties(freeglut_static PROPERTIES LINK_SEARCH_END_STATIC 1)

#find_package(GLUT REQUIRED)

link_directories("C:\\Program Files (x86)\\freeglut\\bin")
set (CMAKE_CXX_FLAGS  "-lfreeglut")
#set (CMAKE_CXX_FLAGS  "-L C:\\Program Files (x86)\\freeglut\\bin -lfreeglut")
#set (CMAKE_CXX_FLAGS  "-o kjk")
#set(CMAKE_C_FLAGS "-L -lm -lGL -lGLU -Wl,-Bstatic -lfreeglut -Wl,-Bdynamic")
#set_target_properties(libfreeglut_static.a PROPERTIES LINKER_LANGUAGE CXX)
#SET(GCC_COVERAGE_LINK_FLAGS    "-lfreeglut")
#find_library(SOMELIB libfreeglut_static.a)

#include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
#include_directories( ${OPENGL_INCLUDE_DIRS})
#add_library(libfreeglut.dll STATIC "C:/Program Files (x86)/freeglut/bin")
#find_package(GLUT REQUIRED)


#include_directories(
#        ${GLUT_LIB_DIR}
#        ${OPENGL_INCLUDE_DIR}
#        ${GLUT_INCLUDE_DIR}
#)

#add_library(libfreeglut.a SHARED ${CMAKE_SOURCE_DIR}/lib/)
#target_include_directories(game ${"c:\\Program Files\\JetBrains\\CLion 2023.2\\bin\\mingw\\x86_64-w64-mingw32\\"})

#message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

#find_package(GLFW3 REQUIRED)
#message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

#target_link_libraries(${PROJECT_NAME} ${LIBS})

add_executable(game main.cpp)

#add_executable(game main.cpp
#        Unit.cpp
#        Unit.h
#        Transport.cpp
#        Transport.h
#        Archer.cpp
#        Archer.h
#)

#target_link_libraries(game PRIVATE Threads::Threads)
#target_link_libraries(game PRIVATE wsock32 ws2_32)
#target_link_libraries(game PRIVATE ${GLUT_LIBRARY})
target_link_libraries(game PRIVATE ${OPENGL_gl_LIBRARY})
#target_link_libraries(game PRIVATE ${OPENGL_freeglut_LIBRARY})
#target_link_libraries(game  ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARY})
#target_link_libraries(game ${OPENGL_gl_LIBRARY} ${OPENGL_freeglut_LIBRARY})