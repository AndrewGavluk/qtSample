    set(CMAKE_CXX_STANDARD 17)
    # Include a library search using find_package() 
    # via REQUIRED, specify that libraries are required
    find_package(Qt5Core REQUIRED)
    find_package(Qt5Gui REQUIRED)
    find_package(Qt5Widgets REQUIRED)
     
    # add meta object compiler (MOC) for Q_OBJECT macro
    QT5_WRAP_CPP(MOC_Files vMainMenu.hpp)
    add_library(forms SHARED vMainMenu.cpp ${MOC_Files})
    
    # specify which libraries to connect
    target_link_libraries(forms Qt5::Core)
    target_link_libraries(forms Qt5::Gui)
    target_link_libraries(forms Qt5::Widgets)