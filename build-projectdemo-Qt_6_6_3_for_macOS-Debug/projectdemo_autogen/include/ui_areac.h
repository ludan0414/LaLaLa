/********************************************************************************
** Form generated from reading UI file 'areac.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREAC_H
#define UI_AREAC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AreaC
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *AreaC)
    {
        if (AreaC->objectName().isEmpty())
            AreaC->setObjectName("AreaC");
        AreaC->resize(400, 300);
        pushButton = new QPushButton(AreaC);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 100, 32));
        label = new QLabel(AreaC);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 80, 351, 141));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\214\272\345\237\2373.png);"));

        retranslateUi(AreaC);

        QMetaObject::connectSlotsByName(AreaC);
    } // setupUi

    void retranslateUi(QWidget *AreaC)
    {
        AreaC->setWindowTitle(QCoreApplication::translate("AreaC", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("AreaC", "\345\233\236\345\210\260\344\270\212\344\270\200\351\241\265", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AreaC: public Ui_AreaC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREAC_H
