    cmake_minimum_required(VERSION 3.8)
    project(Lesson2)
     
    set(CMAKE_CXX_STANDARD 17)
     
    # Include a library search using find_package() 
    # via REQUIRED, specify that libraries are required
    find_package(Qt5Core REQUIRED)
    find_package(Qt5Gui REQUIRED)
    find_package(Qt5Widgets REQUIRED)
     
    # add meta object compiler (MOC) for Q_OBJECT macro
    QT5_WRAP_CPP(MOC_Files fDialog.h)
    add_library(fdialog SHARED fDialog.cpp ${MOC_Files})
    # specify which libraries to connect
    target_link_libraries(fdialog Qt5::Core)
    target_link_libraries(fdialog Qt5::Gui)
    target_link_libraries(fdialog Qt5::Widgets)


    set(SOURCE_FILES main.cpp)
    add_executable(Lesson2 ${SOURCE_FILES})
     
    # specify which libraries to connect
    target_link_libraries(Lesson2 fdialog)