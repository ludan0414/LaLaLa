#include "qpushbutton.h"
#include<QStackedWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include "page1.h"
#include "ui_page1.h"
#include"page2.h"
#include"page3.h"
#include"page4.h"
page1::page1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page1)
{
    ui->setupUi(this);
    this->resize(400,600);
    QPalette palette;
    QPixmap pixmap(":/material2/background_function3.jpg");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
    button1->setText("标准模式");
    button1->setMinimumSize(200,80);
    button2->setMinimumSize(200,80);
    button2->setText("限时模式");
    button3->resize(100,50);
    button3->setText("解锁成就");
    button3->move(10,10);
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach (QPushButton* button, buttons) {
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(211,211,211,80);"
            "    border-style: outset;"
            "    border-width: 2px;"
            "    border-radius: 15px;"
            "    border-color: #AFEEEE;"
            "    font: bold 20px;"
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
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->setContentsMargins(50, 30, 50, 200);
    this->setLayout(layout);
    connect(button1, &QRadioButton::clicked, this,[]() {
        page2 *newpage=new page2;
        newpage->show();
    });
    connect(button2, &QRadioButton::clicked, this,[]() {
        page3 *newpage=new page3;
        newpage->show();
    });
    connect(button3, &QRadioButton::clicked, this,[]() {
        page4 *newpage=new page4;
        newpage->show();
    });
}

page1::~page1()
{
    delete ui;
}


