#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(400,600); //初始化主界面窗口大小，后续将实现按钮大小能够自动适应窗口大小
    ui->pushButton->resize(100,50);
    ui->pushButton->move(150,175);
    ui->pushButton_2->resize(100,50);
    ui->pushButton_2->move(150,275);
    ui->pushButton_3->resize(100,50);
    ui->pushButton_3->move(150,375);
    //初始化三个按钮大小及位置
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog1 *function1=new Dialog1;
    function1->show();
    //弹出功能1窗口
}


void MainWindow::on_pushButton_2_clicked()
{
    Dialog2 *function2=new Dialog2;
    function2->show();
    //弹出功能2窗口
}


void MainWindow::on_pushButton_3_clicked()
{
    Dialog3 *function3=new Dialog3;
    function3->show();
    //弹出功能3窗口
}

