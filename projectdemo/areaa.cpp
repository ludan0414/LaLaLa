#include "areaa.h"
#include "ui_areaa.h"

AreaA::AreaA(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AreaA)
{
    ui->setupUi(this);
    setWindowTitle("区域1");
}

AreaA::~AreaA()
{
    delete ui;
}


void AreaA::on_pushButton_clicked()
{
    emit this->back();
}

