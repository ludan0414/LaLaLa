/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListView *showgarbage;
    QComboBox *choosecity;
    QPushButton *addgarbage;
    QLabel *text;
    QPlainTextEdit *entergarbage;
    QLabel *text2;
    QPushButton *confirm;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        showgarbage = new QListView(Widget);
        showgarbage->setObjectName("showgarbage");
        showgarbage->setGeometry(QRect(140, 100, 491, 491));
        choosecity = new QComboBox(Widget);
        choosecity->addItem(QString());
        choosecity->addItem(QString());
        choosecity->addItem(QString());
        choosecity->addItem(QString());
        choosecity->setObjectName("choosecity");
        choosecity->setGeometry(QRect(20, 150, 69, 22));
        addgarbage = new QPushButton(Widget);
        addgarbage->setObjectName("addgarbage");
        addgarbage->setGeometry(QRect(650, 210, 131, 101));
        text = new QLabel(Widget);
        text->setObjectName("text");
        text->setGeometry(QRect(20, 120, 101, 20));
        entergarbage = new QPlainTextEdit(Widget);
        entergarbage->setObjectName("entergarbage");
        entergarbage->setGeometry(QRect(200, 60, 391, 31));
        text2 = new QLabel(Widget);
        text2->setObjectName("text2");
        text2->setGeometry(QRect(80, 70, 121, 16));
        confirm = new QPushButton(Widget);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(600, 60, 31, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        choosecity->setItemText(0, QCoreApplication::translate("Widget", "\351\273\230\350\256\244", nullptr));
        choosecity->setItemText(1, QCoreApplication::translate("Widget", "\345\214\227\344\272\254", nullptr));
        choosecity->setItemText(2, QCoreApplication::translate("Widget", "\344\270\212\346\265\267", nullptr));
        choosecity->setItemText(3, QCoreApplication::translate("Widget", "\345\271\277\345\267\236", nullptr));

        addgarbage->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\345\236\203\345\234\276", nullptr));
        text->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\344\275\240\347\232\204\345\237\216\345\270\202\357\274\232", nullptr));
        text2->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\345\236\203\345\234\276\357\274\232", nullptr));
        confirm->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
