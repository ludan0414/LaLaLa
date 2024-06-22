/********************************************************************************
** Form generated from reading UI file 'areaa.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREAA_H
#define UI_AREAA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AreaA
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *AreaA)
    {
        if (AreaA->objectName().isEmpty())
            AreaA->setObjectName("AreaA");
        AreaA->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/function2title/title3.png"), QSize(), QIcon::Normal, QIcon::Off);
        AreaA->setWindowIcon(icon);
        label = new QLabel(AreaA);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 341, 201));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\214\272\345\237\2371.png);"));
        pushButton = new QPushButton(AreaA);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 20, 100, 32));

        retranslateUi(AreaA);

        QMetaObject::connectSlotsByName(AreaA);
    } // setupUi

    void retranslateUi(QWidget *AreaA)
    {
        AreaA->setWindowTitle(QCoreApplication::translate("AreaA", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("AreaA", "\345\233\236\345\210\260\344\270\212\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AreaA: public Ui_AreaA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREAA_H
