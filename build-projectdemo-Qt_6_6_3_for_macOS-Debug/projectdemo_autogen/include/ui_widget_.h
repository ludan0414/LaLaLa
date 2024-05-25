/********************************************************************************
** Form generated from reading UI file 'widget_.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET__H
#define UI_WIDGET__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_
{
public:
    QLabel *label;
    QFrame *line_5;
    QFrame *line_4;
    QFrame *line_6;
    QFrame *line_3;
    QLabel *map_background;
    QFrame *line_2;
    QPushButton *AreaA_pushButton;
    QPushButton *AreaB_pushButton;
    QFrame *line;
    QPushButton *AreaD_pushButton;
    QPushButton *AreaC_pushButton;

    void setupUi(QWidget *widget_)
    {
        if (widget_->objectName().isEmpty())
            widget_->setObjectName("widget_");
        widget_->resize(800, 600);
        label = new QLabel(widget_);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 70, 291, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        line_5 = new QFrame(widget_);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(280, 180, 281, 31));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(widget_);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(280, 300, 281, 31));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(widget_);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(280, 300, 281, 31));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(widget_);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(290, 400, 281, 31));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        map_background = new QLabel(widget_);
        map_background->setObjectName("map_background");
        map_background->setGeometry(QRect(30, 80, 711, 501));
        map_background->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\205\250\345\233\276with\345\233\276\344\276\213.png);"));
        line_2 = new QFrame(widget_);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(290, 310, 281, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        AreaA_pushButton = new QPushButton(widget_);
        AreaA_pushButton->setObjectName("AreaA_pushButton");
        AreaA_pushButton->setGeometry(QRect(460, 150, 100, 32));
        AreaA_pushButton->setMouseTracking(true);
        AreaA_pushButton->setAutoFillBackground(true);
        AreaA_pushButton->setAutoDefault(false);
        AreaB_pushButton = new QPushButton(widget_);
        AreaB_pushButton->setObjectName("AreaB_pushButton");
        AreaB_pushButton->setGeometry(QRect(460, 240, 100, 32));
        AreaB_pushButton->setAutoFillBackground(true);
        line = new QFrame(widget_);
        line->setObjectName("line");
        line->setGeometry(QRect(270, 190, 281, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        AreaD_pushButton = new QPushButton(widget_);
        AreaD_pushButton->setObjectName("AreaD_pushButton");
        AreaD_pushButton->setGeometry(QRect(460, 430, 100, 32));
        AreaD_pushButton->setAutoFillBackground(true);
        AreaC_pushButton = new QPushButton(widget_);
        AreaC_pushButton->setObjectName("AreaC_pushButton");
        AreaC_pushButton->setGeometry(QRect(460, 340, 100, 32));
        AreaC_pushButton->setAutoFillBackground(true);

        retranslateUi(widget_);

        QMetaObject::connectSlotsByName(widget_);
    } // setupUi

    void retranslateUi(QWidget *widget_)
    {
        widget_->setWindowTitle(QCoreApplication::translate("widget_", "Form", nullptr));
        label->setText(QCoreApplication::translate("widget_", "\347\202\271\345\207\273\345\257\271\345\272\224\345\214\272\345\237\237\357\274\214\346\237\245\347\234\213\345\236\203\345\234\276\346\241\266\345\210\206\345\270\203\345\233\276", nullptr));
        map_background->setText(QString());
        AreaA_pushButton->setText(QCoreApplication::translate("widget_", "\345\214\272\345\237\237A", nullptr));
        AreaB_pushButton->setText(QCoreApplication::translate("widget_", "\345\214\272\345\237\237B", nullptr));
        AreaD_pushButton->setText(QCoreApplication::translate("widget_", "\345\214\272\345\237\237D", nullptr));
        AreaC_pushButton->setText(QCoreApplication::translate("widget_", "\345\214\272\345\237\237C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_: public Ui_widget_ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET__H
