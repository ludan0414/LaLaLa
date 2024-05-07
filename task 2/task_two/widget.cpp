#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->a = new AreaA;
    connect(this->a,SIGNAL(back()),this,SLOT(comeBackToPrev()));
    this->b = new AreaB;
    connect(this->b,SIGNAL(back()),this,SLOT(comeBackToPrev2()));
    this->c = new AreaC;
    connect(this->c,SIGNAL(back()),this,SLOT(comeBackToPrev3()));
    this->d = new AreaD;
    connect(this->d,SIGNAL(back()),this,SLOT(comeBackToPrev4()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_AreaA_pushButton_clicked()
{
    //this->close();
    this->a->show();
}
void Widget::on_AreaB_pushButton_clicked()
{
    //this->close();
    this->b->show();
}
void Widget::on_AreaC_pushButton_clicked()
{
    //this->close();
    this->c->show();
}
void Widget::on_AreaD_pushButton_clicked()
{
    //this->close();
    this->d->show();
}
void Widget::comeBackToPrev(){
    this->a->hide();
    //this->show();
}
void Widget::comeBackToPrev2(){
    this->b->hide();
    //this->show();
}
void Widget::comeBackToPrev3(){
    this->c->hide();
    //this->show();
}
void Widget::comeBackToPrev4(){
    this->d->hide();
    //this->show();
}
