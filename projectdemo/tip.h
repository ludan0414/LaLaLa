#ifndef TIP_H
#define TIP_H

#include <QWidget>
#include <QPushButton>
#include<QTextEdit>
namespace Ui {
class tip;
}

class tip : public QWidget
{
    Q_OBJECT

public:
    explicit tip(QWidget *parent = nullptr);
    QPushButton *yes=new QPushButton;
    QPushButton *no=new QPushButton;
    QTextEdit *note=new QTextEdit;
    ~tip();


private:
    Ui::tip *ui;
};

#endif // TIP_H
