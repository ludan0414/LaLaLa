#include "widget.h"
#include "./ui_widget.h"
#include <QStandardItemModel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->confirm->setEnabled(0);
}

Widget::~Widget()
{
    delete ui;
}
QString city;
int cityid;
std::vector<std::string> findgarbage(std::string,int);
void Widget::on_comboBox_editTextChanged(const QString &arg1)
{

}


void Widget::on_choosecity_editTextChanged(const QString &arg1)
{

}


void Widget::on_entergarbage_textChanged()
{

}


void Widget::on_choosecity_currentIndexChanged(int index)
{
    city=ui->choosecity->currentText();
    if (city=="北京"){
        cityid=1;
        ui->confirm->setEnabled(1);
    }
    else if (city=="上海"){
        cityid=2;
        ui->confirm->setEnabled(1);
    }
    else if (city=="广州"){
        cityid=3;
        ui->confirm->setEnabled(1);
    }
    else{
        cityid=0;
        ui->confirm->setEnabled(0);
    }
}


void Widget::on_confirm_clicked()
{
    auto word=ui->entergarbage->toPlainText();
    auto tobeshown=findgarbage(word.toStdString(),cityid);
    QStandardItemModel *model = new QStandardItemModel();
    int cnt=0;
    for (auto &i:tobeshown){
        QStandardItem *item = new QStandardItem(QString::fromStdString(i));
        if(++cnt % 2 == 1)
        {
            QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
            linearGrad.setColorAt(0, Qt::cyan);
            linearGrad.setColorAt(1, Qt::cyan);
            QBrush brush(linearGrad);
            item->setBackground(brush);
        }
        model->appendRow(item);
    }
    //总之这里要展示一下
    if (tobeshown.empty()){
        QStandardItem *item = new QStandardItem("啊哦，数据库里暂时没有收录这种垃圾！您可以尝试手动添加。");
        model->appendRow(item);
    }
    ui->showgarbage->setModel(model);
}

