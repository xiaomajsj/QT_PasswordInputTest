#include "settingwindow.h"
#include "ui_settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QWidget(parent),
    uiSettingWindow(new Ui::SettingWindow)
{
    uiSettingWindow->setupUi(this);
}

SettingWindow::~SettingWindow()
{
    delete uiSettingWindow;
}
