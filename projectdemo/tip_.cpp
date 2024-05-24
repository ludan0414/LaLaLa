#include "tip_.h"
#include "ui_tip_.h"
#include<QVBoxLayout>
tip_::tip_(int num,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tip_)
{
    ui->setupUi(this);
    text->resize(400,400);
    text->setHtml(QString("<p style='font-size: 20pt;font-family: 华文新魏;text-align: center;'>挑战结束，<br>本次挑战你总共答对题数为：<br><span style='font-size: 30pt;'>%1</span></p>").arg(num));
    //text->setHtml(QString("<div style='height: 100px; display: flex; justify-content: center; align-items: center; font-family: 华文新魏; font-size: 12pt;'>挑战结束，<br>本次挑战你总共答对题数为：<span style='font-size: 24pt;'>%1</span></div>").arg(num));
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(text);
    this->setLayout(layout);
}

tip_::~tip_()
{
    delete ui;
}
