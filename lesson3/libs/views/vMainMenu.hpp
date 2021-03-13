#pragma once

#include <cstdint>

#include <QDialog>
#include <QtWidgets>

enum MainMenuButt : uint8_t
{
    None,
    OnePlayer,
    Network,
    Options,
    About,
    Exit
};

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    virtual ~MainMenu();

private slots:
    void onClick(const MainMenuButt&);

private:

    inline void addButton(QPushButton*, const MainMenuButt&, const QString& );

    QVBoxLayout *m_Layout;
    QPushButton *m_OnePlayer, 
                *m_Networking,
                *m_Options,
                *m_About,
                *m_Exit;
};
