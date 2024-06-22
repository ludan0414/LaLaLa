/********************************************************************************
** Form generated from reading UI file 'customdic.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMDIC_H
#define UI_CUSTOMDIC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customdic
{
public:
    QLabel *text1;
    QPushButton *change;
    QPushButton *delete_2;
    QPlainTextEdit *enterid;
    QLabel *text2;
    QLabel *text3;
    QComboBox *sort;
    QTableView *viewcustom;
    QLabel *text4;
    QPlainTextEdit *entername;
    QPushButton *new_2;
    QPushButton *save;
    QLabel *label;

    void setupUi(QWidget *customdic)
    {
        if (customdic->objectName().isEmpty())
            customdic->setObjectName("customdic");
        customdic->resize(622, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/function1title/\347\254\224\350\256\260 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        customdic->setWindowIcon(icon);
        customdic->setStyleSheet(QString::fromUtf8(""));
        text1 = new QLabel(customdic);
        text1->setObjectName("text1");
        text1->setGeometry(QRect(70, 20, 241, 61));
        text1->setStyleSheet(QString::fromUtf8("font: 24pt \"\347\273\210\344\271\213\350\212\26101\";\n"
""));
        change = new QPushButton(customdic);
        change->setObjectName("change");
        change->setGeometry(QRect(500, 200, 91, 41));
        change->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        delete_2 = new QPushButton(customdic);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(500, 100, 91, 41));
        delete_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        enterid = new QPlainTextEdit(customdic);
        enterid->setObjectName("enterid");
        enterid->setGeometry(QRect(360, 120, 101, 31));
        enterid->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\347\273\206\351\273\221\";"));
        text2 = new QLabel(customdic);
        text2->setObjectName("text2");
        text2->setGeometry(QRect(360, 80, 71, 31));
        text2->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        text3 = new QLabel(customdic);
        text3->setObjectName("text3");
        text3->setGeometry(QRect(360, 190, 111, 21));
        text3->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        sort = new QComboBox(customdic);
        sort->setObjectName("sort");
        sort->setGeometry(QRect(360, 220, 101, 31));
        viewcustom = new QTableView(customdic);
        viewcustom->setObjectName("viewcustom");
        viewcustom->setGeometry(QRect(20, 80, 321, 391));
        viewcustom->setStyleSheet(QString::fromUtf8("background-color: rgba(170, 170, 255, 30);"));
        text4 = new QLabel(customdic);
        text4->setObjectName("text4");
        text4->setGeometry(QRect(360, 280, 101, 61));
        text4->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        entername = new QPlainTextEdit(customdic);
        entername->setObjectName("entername");
        entername->setGeometry(QRect(360, 330, 101, 31));
        entername->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\347\273\206\351\273\221\";"));
        new_2 = new QPushButton(customdic);
        new_2->setObjectName("new_2");
        new_2->setGeometry(QRect(500, 310, 91, 41));
        new_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        save = new QPushButton(customdic);
        save->setObjectName("save");
        save->setGeometry(QRect(420, 390, 101, 61));
        save->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\273\210\344\271\213\350\212\26101\";"));
        label = new QLabel(customdic);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 41, 41));

        retranslateUi(customdic);

        QMetaObject::connectSlotsByName(customdic);
    } // setupUi

    void retranslateUi(QWidget *customdic)
    {
        customdic->setWindowTitle(QCoreApplication::translate("customdic", "Form", nullptr));
        text1->setText(QCoreApplication::translate("customdic", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">\350\207\252\345\256\232\344\271\211\345\236\203\345\234\276\345\210\227\350\241\250</span></p></body></html>", nullptr));
        change->setText(QCoreApplication::translate("customdic", "\344\277\256\346\224\271", nullptr));
        delete_2->setText(QCoreApplication::translate("customdic", "\345\210\240\351\231\244", nullptr));
        text2->setText(QCoreApplication::translate("customdic", "\345\236\203\345\234\276id", nullptr));
        text3->setText(QCoreApplication::translate("customdic", "\345\236\203\345\234\276\347\261\273\345\236\213", nullptr));
        text4->setText(QCoreApplication::translate("customdic", "\345\236\203\345\234\276\345\220\215\347\247\260", nullptr));
        new_2->setText(QCoreApplication::translate("customdic", "\346\226\260\345\273\272", nullptr));
        save->setText(QCoreApplication::translate("customdic", "\344\277\235\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("customdic", "<html><head/><body><p><img src=\":/material3/\347\254\224\350\256\260.png\"/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customdic: public Ui_customdic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMDIC_H
