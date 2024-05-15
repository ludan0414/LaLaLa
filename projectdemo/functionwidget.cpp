#include "functionwidget.h"
#include "ui_functionwidget.h"

functionwidget::functionwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::functionwidget)
{
    ui->setupUi(this);
}

functionwidget::~functionwidget()
{
    delete ui;
}
