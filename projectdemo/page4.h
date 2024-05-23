#ifndef PAGE4_H
#define PAGE4_H

#include <QWidget>
#include<QListWidget>
namespace Ui {
class page4;
}

class page4 : public QWidget
{
    Q_OBJECT

public:
    explicit page4(QWidget *parent = nullptr);
    ~page4();
    QListWidget *listwidget = new QListWidget(this);

private:
    Ui::page4 *ui;
};

#endif // PAGE4_H
