#include "page4.h"
#include "ui_page4.h"
#include<QVBoxLayout>
#include<QFile>
page4::page4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page4)
{
    ui->setupUi(this);
    setWindowTitle("解锁成就");
    this->resize(600,600);
    QFile infile("achievement.csv");
    if (infile.open(QIODevice::ReadOnly))
    {
        QTextStream stream_text(&infile);
        while (!stream_text.atEnd())
        {
            list.push_back(stream_text.readLine());
        }
        infile.close();
    }
    listwidget->resize(600,600);
    listwidget->setIconSize(QSize(50,50));
    QListWidgetItem *item1 = new QListWidgetItem("铜章：标准模式下一次性答对三题");
    QIcon icon1(":/material3/黄铜章.png");
    QPixmap disabledPixmap1 = icon1.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon1(disabledPixmap1); // 创建禁用状态的图标对象
    if(list[0]=="FALSE")
        item1->setIcon(disabledIcon1);
    else
        item1->setIcon(icon1);
    item1->setSizeHint(QSize(100, 50));
    listwidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem("银章：标准模式下一次性答对五题");
    QIcon icon2(":/material3/银章.png");
    QPixmap disabledPixmap2 = icon2.pixmap(QSize(50, 50), QIcon::Disabled); // 将图标渲染成禁用状态
    QIcon disabledIcon2(disabledPixmap2); // 创建禁用状态的图标对象
    if(list[1]=="FALSE")
        item2->setIcon(disabledIcon2);
    else
        item2->setIcon(icon2);
    item2->setSizeHint(QSize(100, 50));
    listwidget->addItem(item2);
    QListWidgetItem *item3 = new QListWidgetItem("金章：标准模式下一次性答对十题");
    QIcon icon3(":/material3/黄金.png");
    QPixmap disabledPixmap3 = icon3.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon3(disabledPixmap3);
    if(list[2]=="FALSE")
        item3->setIcon(disabledIcon3);
    else
        item3->setIcon(icon3);
    item3->setSizeHint(QSize(100, 50));
    listwidget->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem("铂金：限时模式下一次性答对十题");
    QIcon icon4(":/material3/铂金.png");
    QPixmap disabledPixmap4 = icon4.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon4(disabledPixmap4);
    if(list[3]=="FALSE")
        item4->setIcon(disabledIcon4);
    else
        item4->setIcon(icon4);
    item4->setSizeHint(QSize(100, 50));
    listwidget->addItem(item4);

    QListWidgetItem *item5 = new QListWidgetItem("白金：限时模式下一次性答对二十题");
    QIcon icon5(":/material3/白金.png");
    QPixmap disabledPixmap5 = icon5.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon5(disabledPixmap5);
    if(list[4]=="FALSE")
        item5->setIcon(disabledIcon5);
    else
        item5->setIcon(icon5);
    item5->setSizeHint(QSize(100, 50));
    listwidget->addItem(item5);

    QListWidgetItem *item6 = new QListWidgetItem("王者：此次挑战所有回答全部正确且答题数超过三十");
    QIcon icon6(":/material3/冠军.png");
    QPixmap disabledPixmap6 = icon6.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon6(disabledPixmap6);
    if(list[5]=="FALSE")
        item6->setIcon(disabledIcon6);
    else
        item6->setIcon(icon6);
    item6->setSizeHint(QSize(100, 50));
    listwidget->addItem(item6);

    QListWidgetItem *item7 = new QListWidgetItem("红宝石：标准模式下挑战连对三题");
    QIcon icon7(":/material3/红宝石.png");
    QPixmap disabledPixmap7 = icon7.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon7(disabledPixmap7);
    if(list[6]=="FALSE")
        item7->setIcon(disabledIcon7);
    else
        item7->setIcon(icon7);
    item7->setSizeHint(QSize(100, 50));
    listwidget->addItem(item7);

    QListWidgetItem *item8 = new QListWidgetItem("紫宝石：标准模式下挑战连对五题");
    QIcon icon8(":/material3/紫宝石.png");
    QPixmap disabledPixmap8 = icon8.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon8(disabledPixmap8);
    if(list[7]=="FALSE")
        item8->setIcon(disabledIcon8);
    else
        item8->setIcon(icon8);
    item8->setSizeHint(QSize(100, 50));
    listwidget->addItem(item8);

    QListWidgetItem *item9 = new QListWidgetItem("绿宝石：本次挑战完美避开所有正确答案");
    QIcon icon9(":/material3/绿宝石.png");
    QPixmap disabledPixmap9 = icon9.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon9(disabledPixmap9);
    if(list[8]=="FALSE")
        item9->setIcon(disabledIcon9);
    else
        item9->setIcon(icon9);
    item9->setSizeHint(QSize(100, 50));
    listwidget->addItem(item9);

    QFont font("华文新魏", 14);
    QString styleSheet = "QListWidget::item { background-color: gray; color: white; }"
                         "QListWidget::item::icon { background-color: transparent; }";
    for (int i = 0; i < listwidget->count(); ++i) {
        listwidget->item(i)->setFont(font);
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listwidget);
    this->setLayout(layout);
}

page4::~page4()
{
    delete ui;
}
