
#include "widget_.h"
#include "ui_widget_.h"

widget_::widget_(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_)
{
    ui->setupUi(this);
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach (QPushButton* button, buttons) {
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(211,211,211,80);"
            "    border-style: outset;"
            "    border-width: 2px;"
            "    border-radius: 15px;"
            "    border-color: #AFEEEE;"
            "    font: bold 18px;"
            "    min-width: 2em;"
            "    color: black;" /* 字体颜色 */
            "    font-family: 华文新魏;"
            "    padding: 4px;"
            "    transition: transform 0.2s;"
            "}"
            "QPushButton:hover {"
            "    background-color: rgb(0, 150, 0);"
            "    border-width: 4px;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #6B8E23;"
            "    border-style: inset;"
            "}"
            );
    }
    //ui->AreaA_pushButton->setStyleSheet("QPushButton:hover{background-color:white; color: black;}");
    //ui->AreaB_pushButton->setStyleSheet("QPushButton:hover{background-color:white; color: black;}");
    //ui->AreaC_pushButton->setStyleSheet("QPushButton:hover{background-color:white; color: black;}");
    //ui->AreaD_pushButton->setStyleSheet("QPushButton:hover{background-color:white; color: black;}");
    this->resize(800,600);
    this->a = new AreaA;
    connect(this->a,SIGNAL(back()),this,SLOT(comeBackToPrev()));
    this->b = new AreaB;
    connect(this->b,SIGNAL(back()),this,SLOT(comeBackToPrev2()));
    this->c = new AreaC;
    connect(this->c,SIGNAL(back()),this,SLOT(comeBackToPrev3()));
    this->d = new AreaD;
    connect(this->d,SIGNAL(back()),this,SLOT(comeBackToPrev4()));
}

widget_::~widget_()
{
    delete ui;
}
void widget_::on_AreaA_pushButton_clicked()
{
    //this->close();
    this->a->show();
}
void widget_::on_AreaB_pushButton_clicked()
{
    //this->close();
    this->b->show();
}
void widget_::on_AreaC_pushButton_clicked()
{
    //this->close();
    this->c->show();
}
void widget_::on_AreaD_pushButton_clicked()
{
    //this->close();
    this->d->show();
}
void widget_::comeBackToPrev(){
    this->a->hide();
    //this->show();
}
void widget_::comeBackToPrev2(){
    this->b->hide();
    //this->show();
}
void widget_::comeBackToPrev3(){
    this->c->hide();
    //this->show();
}
void widget_::comeBackToPrev4(){
    this->d->hide();
    //this->show();
}
