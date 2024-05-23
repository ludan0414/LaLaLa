#include "tip_.h"
#include "ui_tip_.h"
#include<QVBoxLayout>
tip_::tip_(int num,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tip_)
{
    ui->setupUi(this);
    text->resize(400,400);
    text->setText(QString("挑战结束，本次挑战你总共答对题数为：%1").arg(num));
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(text);
    this->setLayout(layout);
}

tip_::~tip_()
{
    delete ui;
}
