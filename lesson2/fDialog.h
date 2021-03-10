#pragma once

#include <QDialog>
#include <QtWidgets>

class FDialog : public QDialog
{
    Q_OBJECT

public:
    FDialog(QWidget *parent = nullptr);

signals:
    void findNext(const std::string&, Qt::CaseSensitivity);
    void findPrevious(const std::string&, Qt::CaseSensitivity);

private slots:
    void findClicked();
    void enableFindButton (const std::string&);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox, *backwardCheckBox;
    QPushButton *findButton, *closeButton;

};