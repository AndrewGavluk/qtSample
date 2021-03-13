#include "vMainMenu.hpp"

MainMenu::MainMenu(QWidget *parent){
    m_Layout = new QVBoxLayout{};

    addButton(m_OnePlayer,  MainMenuButt::OnePlayer,    tr("&One player"));
    addButton(m_Networking, MainMenuButt::Network,      tr("&Network"));
    addButton(m_Options,    MainMenuButt::Options,      tr("&Options"));
    addButton(m_About,      MainMenuButt::About,        tr("&About"));
    addButton(m_Exit,       MainMenuButt::Exit,         tr("&Exit"));

    setLayout(m_Layout);
    setWindowTitle("Main menu");
    setFixedHeight(sizeHint().height());
}

MainMenu::~MainMenu(){}

void MainMenu::onClick(const MainMenuButt& value){

}

void MainMenu::addButton(QPushButton* btn, const MainMenuButt& value, const QString& str ){
    static const QSize btnSize = QSize(250, 100);
    btn = new QPushButton{str};
    btn->setFixedSize(btnSize);
    QObject::connect(btn, SIGNAL (Clicked()), this, SLOT(onClick(value)));
    m_Layout->addWidget(btn);
   
}