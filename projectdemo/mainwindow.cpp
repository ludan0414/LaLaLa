#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"page1.h"
#include"MapWidget.h"
#include "widget.h"
//#include "widget_.h"
#include "makedic.hpp"
#include<QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("refuse classification");
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
        MapWidget*function2=new MapWidget;
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


