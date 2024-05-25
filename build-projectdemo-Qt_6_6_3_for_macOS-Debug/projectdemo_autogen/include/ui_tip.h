/********************************************************************************
** Form generated from reading UI file 'tip.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIP_H
#define UI_TIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tip
{
public:

    void setupUi(QWidget *tip)
    {
        if (tip->objectName().isEmpty())
            tip->setObjectName("tip");
        tip->resize(400, 300);

        retranslateUi(tip);

        QMetaObject::connectSlotsByName(tip);
    } // setupUi

    void retranslateUi(QWidget *tip)
    {
        tip->setWindowTitle(QCoreApplication::translate("tip", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tip: public Ui_tip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIP_H
