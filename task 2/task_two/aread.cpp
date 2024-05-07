#include "aread.h"
#include "ui_aread.h"

AreaD::AreaD(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AreaD)
{
    ui->setupUi(this);
}

AreaD::~AreaD()
{
    delete ui;
}
void AreaD::on_pushButton_clicked()
{
    emit this->back();
}
