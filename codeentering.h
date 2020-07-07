#ifndef CODEENTERING_H
#define CODEENTERING_H

#include <QWidget>
#include <QMessageBox>
#include "settingwindow.h"
#include <QQuickWidget>

static QString DeveloperCode = "1234567";  //the true password

namespace Ui {
class CodeEntering;
}

class CodeEntering : public QWidget
{
    Q_OBJECT

public:
    explicit CodeEntering(QWidget *parent = nullptr);
    ~CodeEntering();
    bool eventFilter(QObject *wcg, QEvent *event);

private slots:
    void on_pushButton_ConfirmCode_clicked();

    void on_pushButton_CancelCode_clicked();

private:
    Ui::CodeEntering *uiCodeEntering;
    QString InputCode;
    SettingWindow *wSetEnter;
    //QQuickWidget *VirtualKeyboard;
};

#endif // CODEENTERING_H
