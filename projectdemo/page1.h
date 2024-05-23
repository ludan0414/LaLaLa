#ifndef PAGE1_H
#define PAGE1_H

#include <QWidget>
#include<QPushButton>
class QStackedWidget;
namespace Ui {
class page1;
}

class page1 : public QWidget
{
    Q_OBJECT

public:
    explicit page1(QWidget *parent = nullptr);
    QPushButton *button1=new QPushButton(this);
    QPushButton *button2=new QPushButton(this);
    QPushButton *button3=new QPushButton(this);
    ~page1();


private:
    Ui::page1 *ui;

};
extern int whichpage;

#endif // PAGE1_H
