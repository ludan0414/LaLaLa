#include "customdic.h"
#include "ui_customdic.h"
#include <QStandardItemModel>
struct ret{int a;std::string b;std::string c;};
std::vector<ret> listcustom(int);
customdic::customdic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::customdic)
{
    ui->setupUi(this);
    auto tobeshown=listcustom(1);
    QStandardItemModel* model = new QStandardItemModel();
    int cnt=0;
    for (auto &i:tobeshown){
        model->setItem(cnt,0,new QStandardItem(QString::fromStdString(std::to_string(i.a))));
        model->setItem(cnt,1,new QStandardItem(QString::fromStdString(i.b)));
        model->setItem(cnt,1,new QStandardItem(QString::fromStdString(i.c)));
    }
    //总之这里要展示一下
    if (tobeshown.empty()){
        QStandardItem *item = new QStandardItem("您还没有手动添加垃圾！");
        model->appendRow(item);
    }
    ui->viewcustom->setModel(model);
}

customdic::~customdic()
{
    delete ui;
}
