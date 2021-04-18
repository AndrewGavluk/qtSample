#include "vMainMenu.hpp"

MainMenu::MainMenu(QWidget *parent): startFlag{true}{
    m_Layout = new QVBoxLayout{};
    showMainMenu();
}

void MainMenu::showOPMenu(){
    removeLayout();
    
    addButton(MainMenuButt::OP_Computer,  tr("Play with &coputer"), &MainMenu::showMainMenu);
    addButton(MainMenuButt::OP_Human,     tr("Play with &human"),   &MainMenu::showMainMenu);
    addButton(MainMenuButt::Exit,         tr("&Exit"),              &MainMenu::showMainMenu);

    updateLayout(tr("One player menu"));
}

void MainMenu::showNWMenu(){
    removeLayout();

    addButton(MainMenuButt::NW_ConnectToServer,  tr("&Connect to server"),  &MainMenu::showMainMenu);
    addButton(MainMenuButt::NW_CreateServer,     tr("Create &server"),      &MainMenu::showMainMenu);
    addButton(MainMenuButt::Exit,                tr("&Exit"),               &MainMenu::showMainMenu);

    updateLayout(tr("Network menu"));
}

void MainMenu::showOPTMenu(){
    removeLayout();

    addButton(MainMenuButt::OPT_Gamplay,        tr("&Gameplay options"), &MainMenu::showMainMenu);
    addButton(MainMenuButt::NW_CreateServer,    tr("&Video options"),   &MainMenu::showMainMenu);
    addButton(MainMenuButt::Exit,               tr("&Audio options"),   &MainMenu::showMainMenu);
    addButton(MainMenuButt::Exit,               tr("&Exit"),            &MainMenu::showMainMenu);

    updateLayout(tr("Otions menu"));
}

void MainMenu::showAboutInfo(){
    removeLayout();
    addButton(MainMenuButt::Exit,         tr("&Exit"), &MainMenu::showMainMenu);
    updateLayout(tr("Otions menu"));
}

void MainMenu::showExit(){

    removeLayout();
        
    QPushButton* btn = addButton(MainMenuButt::E_Yes,    tr("Yes"));
    QObject::connect(btn, SIGNAL (clicked()), this, SLOT(showOPMenu()));

    btn = addButton(MainMenuButt::E_No,      tr("&No"));
    QObject::connect(btn, SIGNAL (clicked()), this, SLOT(showNWMenu()));
    
    btn = addButton(MainMenuButt::Exit,         tr("&Exit"));
    QObject::connect(btn, SIGNAL (clicked()), this, SLOT(showOPMenu()));

    updateLayout(tr("Exit menu"));
}

void MainMenu::showMainMenu(){
    if (!startFlag)
        removeLayout();
        
    addButton(MainMenuButt::OnePlayer,  tr("&One player"),  &MainMenu::showOPMenu);
    addButton(MainMenuButt::Network,    tr("&Network"),     &MainMenu::showNWMenu);
    addButton(MainMenuButt::Options,    tr("&Options"),     &MainMenu::showOPTMenu);
    addButton(MainMenuButt::About,      tr("&About"),       &MainMenu::showAboutInfo);
    addButton(MainMenuButt::Exit,       tr("&Exit"),        &MainMenu::showExit);

    updateLayout(tr("Main menu"));
}

MainMenu::~MainMenu(){}

void MainMenu::removeLayout(){
    QLayoutItem *item;
    while((item = m_Layout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}

void MainMenu::updateLayout(const QString& str)
{
    
    if (startFlag)
        setLayout(m_Layout);
    startFlag = false;
    m_Layout->update();
    setWindowTitle(str);
  
}

QPushButton* MainMenu::addButton(const MainMenuButt& value, const QString& str){
    static const QSize btnSize = QSize(250, 100);

    QPushButton* btn = new QPushButton{str};
    btn->setFixedSize(btnSize);
    m_Layout->addWidget(btn);   
    return btn;
}

void MainMenu::addButton(const MainMenuButt& value, const QString& str, void(MainMenu::*fn)()){
    static const QSize btnSize = QSize(250, 100);

    QPushButton* btn = new QPushButton{str};
    btn->setFixedSize(btnSize);
    m_Layout->addWidget(btn);  
    QObject::connect(btn, &QPushButton::clicked, this, fn); 
}
/*
void MainMenu::slotExecute(void(MainMenu::*fn)())
{
    (*fn)();
}*/