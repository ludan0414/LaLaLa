#include "areac.h"
#include "ui_areac.h"

AreaC::AreaC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AreaC)
{
    ui->setupUi(this);
    setWindowTitle("区域3");
}

AreaC::~AreaC()
{
    delete ui;
}
void AreaC::on_pushButton_clicked()
{
    emit this->back();
}
