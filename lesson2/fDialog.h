#pragma once

#include <QDialog>
#include <QtWidgets>

class FDialog : public QDialog
{
    Q_OBJECT

public:
    FDialog(QWidget *parent = nullptr);
    virtual ~FDialog(){}
signals:
    void findNext(const std::wstring&, Qt::CaseSensitivity);
    void findPrevious(const std::wstring&, Qt::CaseSensitivity);

private slots:
    void findClicked();
    void enableFindButton (const std::wstring&);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox, *backwardCheckBox;
    QPushButton *findButton, *closeButton;

};

