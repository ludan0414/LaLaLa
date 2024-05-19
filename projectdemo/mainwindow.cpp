#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"page1.h"
#include "widget.h"
#include "widget_.h"
#include "makedic.hpp"
#include<QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(400,600);
    QWidget *widget=new QWidget(this);
    this->setCentralWidget(widget);
    QVBoxLayout *layout=new QVBoxLayout();
    button1->setMinimumHeight(60);
    button1->setMinimumWidth(170);
    button2->setMinimumHeight(60);
    button2->setMinimumWidth(170);
    button3->setMinimumHeight(60);
    button3->setMinimumWidth(170);
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->setSpacing(60);
    layout->setAlignment(Qt::AlignCenter);
    connect(button1,&QPushButton::clicked,this,[](){
        work();
        readcustomdic();
        Widget *w=new Widget;
        w->show();
    });
    connect(button2,&QPushButton::clicked,this,[](){
        widget_ *function2=new widget_;
        function2->show();
    });
    connect(button3,&QPushButton::clicked,this,[](){
        page1 *function3=new page1;
        function3->show();
    });
    centralWidget()->setLayout(layout);
}
MainWindow::~MainWindow()
{
    delete ui;
}


