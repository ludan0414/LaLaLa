#include "customdic.h"
#include "ui_customdic.h"
#include <QStandardItemModel>
struct ret{int a;std::string b;std::string c;};
std::vector<ret> listcustom(int);
extern int cityid;
extern int begincustom;
void writecustomdic();
void showlist(Ui::customdic*);
void add(std::string,int);
void changesort(int,int);
void del(int);
customdic::customdic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::customdic)
{
    ui->setupUi(this);
    showlist(ui);
    ui->new_2->setEnabled(0);
    ui->change->setEnabled(0);
    ui->delete_2->setEnabled(0);
    ui->viewcustom->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
customdic::~customdic()
{
    delete ui;
}
void showlist(Ui::customdic *ui){
    auto tobeshown=listcustom(cityid);
    QStandardItemModel* model = new QStandardItemModel();
    int cnt=0;
    for (auto &i:tobeshown){
        qDebug()<<i.a<<QString::fromStdString(i.b)<<QString::fromStdString(i.c)<<true;
        model->setItem(cnt,0,new QStandardItem(QString::fromStdString(std::to_string(i.a))));
        model->setItem(cnt,1,new QStandardItem(QString::fromStdString(i.b)));
        model->setItem(cnt,2,new QStandardItem(QString::fromStdString(i.c)));
        cnt++;
    }
    //总之这里要展示一下
    if (tobeshown.empty()){
        QStandardItem *item = new QStandardItem("您还没有手动添加垃圾！");
        model->appendRow(item);
    }
    ui->viewcustom->setModel(model);
    int tot=ui->sort->count();
    for (int i=tot-1;i>-1;i--){
        ui->sort->removeItem(i);
    }
    if (cityid==1){
        ui->sort->addItem("可回收垃圾");
        ui->sort->addItem("有害垃圾");
        ui->sort->addItem("厨余垃圾");
        ui->sort->addItem("其它垃圾");
    }
    if (cityid==2){
        ui->sort->addItem("可回收物");
        ui->sort->addItem("有害垃圾");
        ui->sort->addItem("湿垃圾");
        ui->sort->addItem("干垃圾");
    }
    if (cityid==3){
        ui->sort->addItem("可回收物");
        ui->sort->addItem("有害垃圾");
        ui->sort->addItem("餐厨垃圾");
        ui->sort->addItem("其它垃圾");
    }
}
void customdic::on_new_2_clicked()
{
    int sort=ui->sort->currentIndex();
    if (sort==3)    sort=8;
    if (sort==2)    sort=4;
    if (sort==1)    sort=2;
    if (sort==0)    sort=1;
    std::string name=ui->entername->toPlainText().toStdString();
    qDebug()<<name<<sort<<true;
    add(name,sort);
    showlist(ui);
    ui->enterid->clear();
    ui->entername->clear();
    ui->new_2->setEnabled(0);
    ui->change->setEnabled(0);
    ui->delete_2->setEnabled(0);
}


void customdic::on_entername_textChanged()
{
    if (ui->entername->toPlainText()!=""){
        ui->new_2->setEnabled(1);
    }
}


void customdic::on_change_clicked()
{
    int id=ui->enterid->toPlainText().toInt();
    int sort=ui->sort->currentIndex();
    if (sort==3)    sort=8;
    if (sort==2)    sort=4;
    if (sort==1)    sort=2;
    if (sort==0)    sort=1;
    if (id>=begincustom){
        changesort(id,sort);
    }
    showlist(ui);
    ui->enterid->clear();
    ui->entername->clear();
    ui->new_2->setEnabled(0);
    ui->change->setEnabled(0);
    ui->delete_2->setEnabled(0);
}


void customdic::on_enterid_textChanged()
{
    if (ui->enterid->toPlainText()!=""){
        ui->change->setEnabled(1);
        ui->delete_2->setEnabled(1);
    }
}


void customdic::on_delete_2_clicked()
{
    int id=ui->enterid->toPlainText().toInt();
    if (id>=begincustom)    del(id);
    showlist(ui);
    ui->enterid->clear();
    ui->entername->clear();
    ui->new_2->setEnabled(0);
    ui->change->setEnabled(0);
    ui->delete_2->setEnabled(0);
}


void customdic::on_save_clicked()
{
    writecustomdic();
}
void customdic::on_pushButton_clicked()
{

}
