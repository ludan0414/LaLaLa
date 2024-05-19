
#include "widget_.h"
#include "ui_widget_.h"

widget_::widget_(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_)
{
    ui->setupUi(this);
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
