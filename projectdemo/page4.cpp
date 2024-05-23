#include "page4.h"
#include "ui_page4.h"
#include<QVBoxLayout>
page4::page4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page4)
{
    ui->setupUi(this);
    this->resize(600,600);
    listwidget->resize(600,600);
    listwidget->setIconSize(QSize(50,50));
    QListWidgetItem *item1 = new QListWidgetItem("铜章：答完题库中1/6的题目");
    QIcon icon1(":/material3/黄铜章.png");
    QPixmap disabledPixmap1 = icon1.pixmap(QSize(50, 50), QIcon::Disabled); // 将图标渲染成禁用状态
    QIcon disabledIcon1(disabledPixmap1); // 创建禁用状态的图标对象
    item1->setIcon(disabledIcon1);
    item1->setSizeHint(QSize(100, 50));
    listwidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem("银章：答完题库中1/3的题目");
    QIcon icon2(":/material3/银章.png");
    QPixmap disabledPixmap2 = icon2.pixmap(QSize(50, 50), QIcon::Disabled); // 将图标渲染成禁用状态
    QIcon disabledIcon2(disabledPixmap2); // 创建禁用状态的图标对象
    item2->setIcon(disabledIcon2); // 设置图标
    item2->setSizeHint(QSize(100, 50));
    listwidget->addItem(item2);
    QListWidgetItem *item3 = new QListWidgetItem("银章：答完题库中1/2的题目");
    QIcon icon3(":/material3/黄金.png");
    QPixmap disabledPixmap3 = icon3.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon3(disabledPixmap3);
    item3->setIcon(disabledIcon3);
    item3->setSizeHint(QSize(100, 50));
    listwidget->addItem(item3);

    QListWidgetItem *item4 = new QListWidgetItem("铂金：答完题库中2/3的题目");
    QIcon icon4(":/material3/铂金.png");
    QPixmap disabledPixmap4 = icon4.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon4(disabledPixmap4);
    item4->setIcon(disabledIcon4);
    item4->setSizeHint(QSize(100, 50));
    listwidget->addItem(item4);

    QListWidgetItem *item5 = new QListWidgetItem("白金：答完题库中5/6的题目");
    QIcon icon5(":/material3/白金.png");
    QPixmap disabledPixmap5 = icon5.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon5(disabledPixmap5);
    item5->setIcon(disabledIcon5);
    item5->setSizeHint(QSize(100, 50));
    listwidget->addItem(item5);

    QListWidgetItem *item6 = new QListWidgetItem("王者：答完题库中所有的题目");
    QIcon icon6(":/material3/冠军.png");
    QPixmap disabledPixmap6 = icon6.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon6(disabledPixmap6);
    item6->setIcon(disabledIcon6);
    item6->setSizeHint(QSize(100, 50));
    listwidget->addItem(item6);

    QListWidgetItem *item7 = new QListWidgetItem("红宝石：标准模式下回答全部正确");
    QIcon icon7(":/material3/红宝石.png");
    QPixmap disabledPixmap7 = icon7.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon7(disabledPixmap7);
    item7->setIcon(disabledIcon7);
    item7->setSizeHint(QSize(100, 50));
    listwidget->addItem(item7);

    QListWidgetItem *item8 = new QListWidgetItem("紫宝石：限时模式下回答全部正确");
    QIcon icon8(":/material3/紫宝石.png");
    QPixmap disabledPixmap8 = icon8.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon8(disabledPixmap8);
    item8->setIcon(disabledIcon8);
    item8->setSizeHint(QSize(100, 50));
    listwidget->addItem(item8);

    QListWidgetItem *item9 = new QListWidgetItem("绿宝石：此次挑战回答全部错误");
    QIcon icon9(":/material3/绿宝石.png");
    QPixmap disabledPixmap9 = icon9.pixmap(QSize(50, 50), QIcon::Disabled);
    QIcon disabledIcon9(disabledPixmap9);
    item9->setIcon(disabledIcon9);
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
