cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

find_package(OpenCV REQUIRED)

find_package(Boost 1.70.0 COMPONENTS system filesystem REQUIRED)
find_package(Boost 1.70.0 COMPONENTS system filesystem serialization REQUIRED)

add_executable(${BINARY}_run ${SOURCES})
add_executable(Server Server.cpp)
add_executable(Client Client.cpp)

add_library(${BINARY}_lib STATIC ${SOURCES})

include_directories( ${OpenCV_INCLUDE_DIRS})

link_directories(${Boost_LIBRARY_DIR})

target_link_libraries(Client ${OpenCV_LIBS} )
target_link_libraries(Client ${Boost_LIBRARIES})

target_link_libraries(Server ${OpenCV_LIBS} )
target_link_libraries(Server ${Boost_LIBRARIES})
