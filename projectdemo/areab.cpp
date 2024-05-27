#include "areab.h"
#include "ui_areab.h"

AreaB::AreaB(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AreaB)
{
    ui->setupUi(this);
    setWindowTitle("区域2");
}

AreaB::~AreaB()
{
    delete ui;
}
void AreaB::on_pushButton_clicked()
{
    emit this->back();
}
