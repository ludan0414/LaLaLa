#include "qpushbutton.h"
#include<QStackedWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include "page1.h"
#include "ui_page1.h"
#include"page2.h"
page1::page1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page1)
{
    ui->setupUi(this);
    this->resize(400,600);
    button1->setText("标准模式");
    button1->setMinimumSize(200,100);
    button2->setMinimumSize(200,100);
    button2->setText("限时模式");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->setContentsMargins(50, 100, 50, 100);
    this->setLayout(layout);
    connect(button1, &QRadioButton::clicked, this,[]() {
        page2 *newpage=new page2;
        newpage->show();
    });
}

page1::~page1()
{
    delete ui;
}


