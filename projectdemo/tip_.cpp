#include "tip_.h"
#include "ui_tip_.h"
#include<QVBoxLayout>
tip_::tip_(int num,bool s,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tip_)
{
    ui->setupUi(this);
    text->resize(400,400);
    text->setHtml(QString("<p style='font-size: 20pt;font-family: 华文新魏;text-align: center;'>挑战结束，<br>本次挑战你总共答对题数为：<br><span style='font-size: 30pt;'>%1</span></p>").arg(num));
    QString htmlString = "<p style='font-size: 20pt;font-family: 华文新魏;text-align: center;'>挑战结束，<br>本次挑战你总共答对题数为：<br><span style='font-size: 30pt;'>%1</span></p>";
    if (s) {
        htmlString += "<p style='font-size: 20pt;font-family: 华文新魏;text-align: center;'>恭喜您解锁了新的成就，快去看看吧！</p>";
    }
    text->setHtml(htmlString.arg(num));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(text);
    this->setLayout(layout);
}

tip_::~tip_()
{
    delete ui;
}
