#include "codeentering.h"
#include "ui_codeentering.h"

CodeEntering::CodeEntering(QWidget *parent) :
    QWidget(parent),
    uiCodeEntering(new Ui::CodeEntering)
{

    uiCodeEntering->setupUi(this);
    /*
     load the eventfilter to implement: click elsewhere, the text input field lost focus
    */
    uiCodeEntering->CodeEnterField->installEventFilter(this);
    this->installEventFilter(this);


    //try to implement qml keyboard, not succeed yet
   /*
    VirtualKeyboard = new QQuickWidget(this);
    VirtualKeyboard->setResizeMode(QQuickWidget::SizeRootObjectToView);
    VirtualKeyboard->setSource(QUrl("/myQML/Keyboard.qml"));
   // VirtualKeyboard->setFixedSize(this->width(),this->height()/4);
    VirtualKeyboard->move(0, this->height()- VirtualKeyboard->height());
   */
}

CodeEntering::~CodeEntering()
{
    delete uiCodeEntering;
}

void CodeEntering::on_pushButton_ConfirmCode_clicked()
{
    /*
    compares the input password and the exact password
     */
    InputCode=uiCodeEntering->CodeEnterField->text();
    if(InputCode==DeveloperCode)
    {
     this->hide();
     wSetEnter=new SettingWindow;
     wSetEnter->show();
     delete this;
    }
    else
    {
     QMessageBox::information(this,tr("Code entering"),tr("You have entered the wrong code, please try again"));
    }
}

void CodeEntering::on_pushButton_CancelCode_clicked()
{
    this->hide();
    delete this;
}

/*
 Use eventfiler to implement: clicking elsewhere, the text input field lost focus
 */
bool CodeEntering::eventFilter(QObject *wcg, QEvent *event)
{
    if(wcg==this){
        if(event->type() == QEvent::MouseButtonPress){
                    if( uiCodeEntering->CodeEnterField->hasFocus()){
                        uiCodeEntering->CodeEnterField->clearFocus();
                    }
                }

}
    return QWidget::eventFilter(wcg,event);
}
