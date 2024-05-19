#ifndef WIDGET__H
#define WIDGET__H

#include <QWidget>
#include<QPushButton>
#include "areaa.h"
#include "areab.h"
#include "areac.h"
#include "aread.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class widget_;
}
QT_END_NAMESPACE
class AreaA;
class AreaB;
class AreaC;
class AreaD;
class widget_ : public QWidget
{
    Q_OBJECT

public:
    explicit widget_(QWidget *parent = nullptr);
    ~widget_();
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
    Ui::widget_ *ui;
};

#endif // WIDGET__H

