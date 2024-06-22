/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
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
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/function1title/title2.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8(""));
        showgarbage = new QListView(Widget);
        showgarbage->setObjectName("showgarbage");
        showgarbage->setGeometry(QRect(150, 130, 491, 461));
        showgarbage->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";"));
        choosecity = new QComboBox(Widget);
        choosecity->addItem(QString());
        choosecity->addItem(QString());
        choosecity->addItem(QString());
        choosecity->addItem(QString());
        choosecity->setObjectName("choosecity");
        choosecity->setGeometry(QRect(20, 220, 91, 31));
        choosecity->setStyleSheet(QString::fromUtf8("font: 12pt;"));
        addgarbage = new QPushButton(Widget);
        addgarbage->setObjectName("addgarbage");
        addgarbage->setGeometry(QRect(650, 210, 131, 101));
        addgarbage->setStyleSheet(QString::fromUtf8("font: 18pt \"Microsoft YaHei UI\";"));
        text = new QLabel(Widget);
        text->setObjectName("text");
        text->setGeometry(QRect(10, 190, 141, 20));
        text->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        entergarbage = new QPlainTextEdit(Widget);
        entergarbage->setObjectName("entergarbage");
        entergarbage->setGeometry(QRect(180, 90, 421, 31));
        entergarbage->setStyleSheet(QString::fromUtf8("border :0 px;\n"
"font: 13pt \"\347\273\210\344\271\213\350\212\26101\";"));
        entergarbage->setCursorWidth(1);
        text2 = new QLabel(Widget);
        text2->setObjectName("text2");
        text2->setGeometry(QRect(150, 40, 421, 41));
        text2->setStyleSheet(QString::fromUtf8("font: 24pt \"\347\273\210\344\271\213\350\212\26101\";"));
        confirm = new QPushButton(Widget);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(610, 90, 61, 31));
        confirm->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(150, 90, 31, 31));
        textEdit->setStyleSheet(QString::fromUtf8("background-image: url(:/material3/\346\220\234\347\264\242.png);\n"
"border: 0px"));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 390, 111, 151));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(660, 390, 110, 150));

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
        entergarbage->setPlainText(QString());
        text2->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\345\236\203\345\234\276\357\274\232", nullptr));
        confirm->setText(QCoreApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><img src=\":/material3/2.jpg\"/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><img src=\":/material3/4.jpg\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
