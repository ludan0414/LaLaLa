/********************************************************************************
** Form generated from reading UI file 'page1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE1_H
#define UI_PAGE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page1
{
public:

    void setupUi(QWidget *page1)
    {
        if (page1->objectName().isEmpty())
            page1->setObjectName("page1");
        page1->resize(400, 300);

        retranslateUi(page1);

        QMetaObject::connectSlotsByName(page1);
    } // setupUi

    void retranslateUi(QWidget *page1)
    {
        page1->setWindowTitle(QCoreApplication::translate("page1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page1: public Ui_page1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE1_H
