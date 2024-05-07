/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *map_background;
    QPushButton *AreaA_pushButton;
    QPushButton *AreaB_pushButton;
    QPushButton *AreaC_pushButton;
    QPushButton *AreaD_pushButton;
    QLabel *label;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        map_background = new QLabel(Widget);
        map_background->setObjectName("map_background");
        map_background->setGeometry(QRect(30, 80, 711, 501));
        map_background->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\205\250\345\233\276with\345\233\276\344\276\213.png);"));
        AreaA_pushButton = new QPushButton(Widget);
        AreaA_pushButton->setObjectName("AreaA_pushButton");
        AreaA_pushButton->setGeometry(QRect(460, 150, 100, 32));
        AreaB_pushButton = new QPushButton(Widget);
        AreaB_pushButton->setObjectName("AreaB_pushButton");
        AreaB_pushButton->setGeometry(QRect(460, 240, 100, 32));
        AreaC_pushButton = new QPushButton(Widget);
        AreaC_pushButton->setObjectName("AreaC_pushButton");
        AreaC_pushButton->setGeometry(QRect(460, 340, 100, 32));
        AreaD_pushButton = new QPushButton(Widget);
        AreaD_pushButton->setObjectName("AreaD_pushButton");
        AreaD_pushButton->setGeometry(QRect(460, 430, 100, 32));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 70, 291, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        line = new QFrame(Widget);
        line->setObjectName("line");
        line->setGeometry(QRect(270, 190, 281, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Widget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(290, 310, 281, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Widget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(290, 390, 281, 31));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Widget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(290, 400, 281, 31));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(Widget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(280, 300, 281, 31));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(Widget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(280, 180, 281, 31));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        map_background->setText(QString());
        AreaA_pushButton->setText(QCoreApplication::translate("Widget", "\345\214\272\345\237\237A", nullptr));
        AreaB_pushButton->setText(QCoreApplication::translate("Widget", "\345\214\272\345\237\237B", nullptr));
        AreaC_pushButton->setText(QCoreApplication::translate("Widget", "\345\214\272\345\237\237C", nullptr));
        AreaD_pushButton->setText(QCoreApplication::translate("Widget", "\345\214\272\345\237\237D", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\202\271\345\207\273\345\257\271\345\272\224\345\214\272\345\237\237\357\274\214\346\237\245\347\234\213\345\236\203\345\234\276\346\241\266\345\210\206\345\270\203\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
