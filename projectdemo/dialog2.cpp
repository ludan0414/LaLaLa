#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    this->resize(800,600); //初始化功能2窗口大小
}

Dialog2::~Dialog2()
{
    delete ui;
}
