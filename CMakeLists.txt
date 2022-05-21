cmake_minimum_required(VERSION 3.23.0)

project(design_principles)

set(PRINCIPLE "solid/single_responsibility.cpp" CACHE STRING "Enter the principle to be run")

message(${PRINCIPLE})

add_executable(
    ${PROJECT_NAME}
    ${PRINCIPLE}
    )

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.79.0) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
