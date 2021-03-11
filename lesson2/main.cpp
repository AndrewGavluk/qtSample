    #include <QtWidgets>
    #include <QApplication>

    #include"fDialog.h"
     
    int main(int argc, char *argv[]) {
     
        QApplication app(argc, argv);
        
        FDialog *dialog = new FDialog{};
        dialog->show();

        return app.exec();
    }