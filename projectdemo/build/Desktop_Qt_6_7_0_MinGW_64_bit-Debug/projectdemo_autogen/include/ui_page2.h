/********************************************************************************
** Form generated from reading UI file 'page2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE2_H
#define UI_PAGE2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page2
{
public:

    void setupUi(QWidget *page2)
    {
        if (page2->objectName().isEmpty())
            page2->setObjectName("page2");
        page2->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/function3title/title4.png"), QSize(), QIcon::Normal, QIcon::Off);
        page2->setWindowIcon(icon);

        retranslateUi(page2);

        QMetaObject::connectSlotsByName(page2);
    } // setupUi

    void retranslateUi(QWidget *page2)
    {
        page2->setWindowTitle(QCoreApplication::translate("page2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page2: public Ui_page2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE2_H
