#include "fDialog.h"

FDialog::FDialog(QWidget * parent) : QDialog(parent){
    /*QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox, *backwardCheckBox;
    QPushButton *findButton, *closeButton;*/
    label = new QLabel{tr("Find &what")};
    
    lineEdit = new QLineEdit{};
    label->setBuddy(lineEdit);
    QObject::connect(lineEdit, SIGNAL (textChanged(const std::string &)), 
                    this, SLOT(enableFindButton(const std::string &)));

    caseCheckBox = new QCheckBox{tr("Match &case")};
    backwardCheckBox = new QCheckBox{tr("Search &backward")};

    findButton = new QPushButton{tr("&Find")};
    findButton->setDefault(true);
    findButton->setEnabled(false);
    QObject::connect(findButton, SIGNAL (Clicked()), 
                    this, SLOT(findClicked(const std::string &)));

    closeButton = new QPushButton{tr("&close")};
    QObject::connect(closeButton, SIGNAL (Clicked()), 
                    this, SLOT(close()));

}
