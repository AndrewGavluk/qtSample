#pragma once

#include <memory>
#include <vector>

#include <cstdint>

#include <QDialog>
#include <QtWidgets>

#include "vMainMenu.hpp"

enum MainMenuButt : uint8_t
{
    None,
    OnePlayer,
    Network,
    Options,
    About,
    Exit,

    OP_Computer,
    OP_Human,

    NW_CreateServer,
    NW_ConnectToServer,
    
    OPT_Gamplay,
    OPT_Video,
    OPT_Audio,

    A_About,

    E_Yes,
    E_No
};

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    virtual ~MainMenu();

private slots:
    void showMainMenu();
    void showOPMenu();
    void showNWMenu();
    void showOPTMenu();
    void showAboutInfo();
    

private:
    void showExit();

    void slotExecute(void(MainMenu::*fn)());
    void addButton(const MainMenuButt&, const QString&, void(MainMenu::*fn)());
    void removeLayout();
    void updateLayout(const QString&);

    //std::vector <std::shared_ptr <QPushButton> > m_Buttons;
    QVBoxLayout *m_Layout;
    MainMenuButt* m_State;

    bool startFlag;
};
