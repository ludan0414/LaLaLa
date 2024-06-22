/********************************************************************************
** Form generated from reading UI file 'tip_.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIP__H
#define UI_TIP__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tip_
{
public:

    void setupUi(QWidget *tip_)
    {
        if (tip_->objectName().isEmpty())
            tip_->setObjectName("tip_");
        tip_->resize(400, 300);

        retranslateUi(tip_);

        QMetaObject::connectSlotsByName(tip_);
    } // setupUi

    void retranslateUi(QWidget *tip_)
    {
        tip_->setWindowTitle(QCoreApplication::translate("tip_", "\344\275\234\347\255\224\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tip_: public Ui_tip_ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIP__H
