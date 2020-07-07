#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "codeentering.h"
#include "settingwindow.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_EnterCode_clicked();

private:
    Ui::MainWindow *ui;
    CodeEntering *wCodeEnter;

};
#endif // MAINWINDOW_H
