#include<QStackedWidget>
#include<QVBoxLayout>
#include "widget_page.h"
#include "ui_widget_page.h"
#include"page1.h"
#include"page2.h"
#include"QPushButton"
widget_page::widget_page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_page)
{
    ui->setupUi(this);
    page1* Page1=new page1;
    QVBoxLayout *layout=new QVBoxLayout(Page1);
    QStackedWidget* stackedwidget=new QStackedWidget;
    layout->addWidget(stackedwidget);
    page2* Page2=new page2;
    stackedwidget->addWidget(Page2);
    QPushButton *button = new QPushButton("Next Page");
    layout->addWidget(button);
    QObject::connect(button, &QPushButton::clicked, [stackedwidget]() {
        int currentIndex = stackedwidget->currentIndex();
        int nextIndex = (currentIndex + 1) % stackedwidget->count();
        stackedwidget->setCurrentIndex(nextIndex);
    });
}

widget_page::~widget_page()
{
    delete ui;
}
