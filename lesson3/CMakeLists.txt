    cmake_minimum_required(VERSION 3.8)
    project(ChessGame)
     
    set(CMAKE_CXX_STANDARD 17)

    set(SOURCE_FILES main.cpp)
    add_executable(ChessGame ${SOURCE_FILES})
    
    add_subdirectory(libs) 
    
    # specify which libraries to connect
    target_link_libraries(ChessGame forms)