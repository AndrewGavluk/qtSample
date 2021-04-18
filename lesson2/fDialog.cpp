#include "fDialog.h"

FDialog::FDialog(QWidget * parent) : QDialog(parent){
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

    closeButton = new QPushButton{tr("&Close")};
    QObject::connect(closeButton, SIGNAL (Clicked()), 
                    this, SLOT(close()));
                
    QHBoxLayout *topLeftLayout = new QHBoxLayout{};
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout{};
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout{};
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout{};
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    
    setLayout(mainLayout);
    setWindowTitle("Find");
    setFixedHeight(sizeHint().height());
}   

void FDialog::findClicked(){
    std::wstring text = lineEdit->text().toStdWString();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    
    if(backwardCheckBox->isChecked())
        emit findPrevious(text, cs);
    else
        emit findNext(text, cs);
}

void FDialog::enableFindButton(const std::wstring& wstr){
    findButton->setEnabled(!wstr.empty());
}