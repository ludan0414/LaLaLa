/********************************************************************************
** Form generated from reading UI file 'dialog3.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG3_H
#define UI_DIALOG3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog3
{
public:
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QTextEdit *textEdit;

    void setupUi(QDialog *Dialog3)
    {
        if (Dialog3->objectName().isEmpty())
            Dialog3->setObjectName("Dialog3");
        Dialog3->resize(400, 300);
        radioButton_2 = new QRadioButton(Dialog3);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(90, 100, 97, 22));
        radioButton_3 = new QRadioButton(Dialog3);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(90, 150, 97, 22));
        radioButton_4 = new QRadioButton(Dialog3);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(90, 200, 97, 22));
        radioButton_5 = new QRadioButton(Dialog3);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(90, 250, 97, 22));
        textEdit = new QTextEdit(Dialog3);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(90, 20, 104, 70));

        retranslateUi(Dialog3);

        QMetaObject::connectSlotsByName(Dialog3);
    } // setupUi

    void retranslateUi(QDialog *Dialog3)
    {
        Dialog3->setWindowTitle(QCoreApplication::translate("Dialog3", "Dialog", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Dialog3", "RadioButton", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Dialog3", "RadioButton", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Dialog3", "RadioButton", nullptr));
        radioButton_5->setText(QCoreApplication::translate("Dialog3", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog3: public Ui_Dialog3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG3_H
