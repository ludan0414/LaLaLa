#include "areac.h"
#include "ui_areac.h"

AreaC::AreaC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AreaC)
{
    ui->setupUi(this);
}

AreaC::~AreaC()
{
    delete ui;
}
void AreaC::on_pushButton_clicked()
{
    emit this->back();
}
