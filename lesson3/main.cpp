#include <iostream>
#include <QApplication>

#include "libs/views/vMainMenu.hpp"
     
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    try
    {
        MainMenu* menu = new MainMenu{};
        menu->show();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return app.exec();
}