/********************************************************************************
** Form generated from reading UI file 'aread.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREAD_H
#define UI_AREAD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AreaD
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *AreaD)
    {
        if (AreaD->objectName().isEmpty())
            AreaD->setObjectName("AreaD");
        AreaD->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/function2title/title3.png"), QSize(), QIcon::Normal, QIcon::Off);
        AreaD->setWindowIcon(icon);
        pushButton = new QPushButton(AreaD);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 100, 32));
        label = new QLabel(AreaD);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 70, 371, 221));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\214\272\345\237\2374.png);"));

        retranslateUi(AreaD);

        QMetaObject::connectSlotsByName(AreaD);
    } // setupUi

    void retranslateUi(QWidget *AreaD)
    {
        AreaD->setWindowTitle(QCoreApplication::translate("AreaD", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("AreaD", "\345\233\236\345\210\260\344\270\212\344\270\200\351\241\265", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AreaD: public Ui_AreaD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREAD_H
