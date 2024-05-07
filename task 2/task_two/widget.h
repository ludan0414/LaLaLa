#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include "areaa.h"
#include "areab.h"
#include "areac.h"
#include "aread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class AreaA;
class AreaB;
class AreaC;
class AreaD;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    AreaA *a = NULL;
    AreaB *b = NULL;
    AreaC *c = NULL;
    AreaD *d = NULL;

private slots:
    void on_AreaA_pushButton_clicked();
    void comeBackToPrev();

    void on_AreaB_pushButton_clicked();
    void comeBackToPrev2();
    void on_AreaC_pushButton_clicked();
    void comeBackToPrev3();
    void on_AreaD_pushButton_clicked();
    void comeBackToPrev4();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

