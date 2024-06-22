/********************************************************************************
** Form generated from reading UI file 'page3.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE3_H
#define UI_PAGE3_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page3
{
public:

    void setupUi(QWidget *page3)
    {
        if (page3->objectName().isEmpty())
            page3->setObjectName("page3");
        page3->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/function3title/title4.png"), QSize(), QIcon::Normal, QIcon::Off);
        page3->setWindowIcon(icon);

        retranslateUi(page3);

        QMetaObject::connectSlotsByName(page3);
    } // setupUi

    void retranslateUi(QWidget *page3)
    {
        page3->setWindowTitle(QCoreApplication::translate("page3", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page3: public Ui_page3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE3_H
