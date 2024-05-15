#include "tip.h"
#include "ui_tip.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include "page2.h"
tip::tip(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tip)
{
    ui->setupUi(this);
    yes->setText("是");
    no->setText("否");
    note->setText("你尚未作答当前题目，是否要跳过直接回答下一题？");
    QVBoxLayout *layout1=new QVBoxLayout;
    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(yes);
    layout2->addWidget(no);
    layout1->addWidget(note);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    this->setLayout(layout);
    connect(yes,&QPushButton::clicked,this,[this](){
        page2 *newpage=new page2;
        newpage->show();
        this->close();
    });
    connect(no,&QPushButton::clicked,this,[this](){
        this->close();
    });
}

tip::~tip()
{
    delete ui;
}
