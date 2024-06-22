/********************************************************************************
** Form generated from reading UI file 'areab.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREAB_H
#define UI_AREAB_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AreaB
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *AreaB)
    {
        if (AreaB->objectName().isEmpty())
            AreaB->setObjectName("AreaB");
        AreaB->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/function2title/title3.png"), QSize(), QIcon::Normal, QIcon::Off);
        AreaB->setWindowIcon(icon);
        pushButton = new QPushButton(AreaB);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 100, 32));
        label = new QLabel(AreaB);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 80, 351, 171));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\214\272\345\237\2372.png);"));

        retranslateUi(AreaB);

        QMetaObject::connectSlotsByName(AreaB);
    } // setupUi

    void retranslateUi(QWidget *AreaB)
    {
        AreaB->setWindowTitle(QCoreApplication::translate("AreaB", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("AreaB", "\345\233\236\345\210\260\344\270\212\344\270\200\351\241\265", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AreaB: public Ui_AreaB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREAB_H
