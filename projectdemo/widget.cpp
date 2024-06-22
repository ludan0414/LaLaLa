#include "widget.h"
#include "./ui_widget.h"
#include "customdic.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QTextCursor>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("垃圾检索");
    ui->confirm->setEnabled(0);
    ui->addgarbage->setEnabled(0);
    ui->textEdit->setEnabled(0);
    ui->choosecity->setItemIcon(1,QIcon(":/material3/天坛.png"));
    ui->choosecity->setItemIcon(2,QIcon(":/material3/上海.png"));
    ui->choosecity->setItemIcon(3,QIcon(":/material3/广州塔.png"));
    QList<QPushButton *> allButtons = this->findChildren<QPushButton *>();
    for (QPushButton *button : allButtons) {
        button->setStyleSheet(
            "QPushButton {"
            "    border-style: outset;"
            "    border-width: 2px;"
            "    border-radius: 10px;"
            "    border-color: #AFEEEE;"
            "    font: bold 18px;"
            "    min-width: 2em;"
            "    color: black;" /* 字体颜色 */
            "    padding: 4px;"
            "    transition: transform 0.2s;"
            "}"
            "QPushButton:hover {"
            "    background-color: rgb(135, 206, 235);"
            "    border-width: 4px;"
            "}"
            "QPushButton:pressed {"
            "    background-color: rgb(28,134,238);"
            "    border-style: inset;"
            "}"
            );
    }
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
        ui->addgarbage->setEnabled(1);
    }
    else if (city=="上海"){
        cityid=2;
        ui->confirm->setEnabled(1);
        ui->addgarbage->setEnabled(1);
    }
    else if (city=="广州"){
        cityid=3;
        ui->confirm->setEnabled(1);
        ui->addgarbage->setEnabled(1);
    }
    else{
        cityid=0;
        ui->confirm->setEnabled(0);
        ui->addgarbage->setEnabled(0);
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
            QBrush brusho(QColor(78,228,233,55));
            item->setBackground(brusho);
        }
        else{
            QBrush brusho(QColor(243,241,209,100));
            item->setBackground(brusho);
        }
        model->appendRow(item);
    }
    //总之这里要展示一下
    if (tobeshown.empty()){
        QStandardItem *item = new QStandardItem("啊哦，数据库里暂时没有收录这种垃圾！您可以尝试手动添加。");
        model->appendRow(item);
    }
    ui->showgarbage->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->showgarbage->setModel(model);
}


void Widget::on_addgarbage_clicked()
{
    customdic *Customdic = new customdic;
    Customdic->show();
}
