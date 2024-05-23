#ifndef TIP__H
#define TIP__H

#include <QWidget>
#include<QTextBrowser>
namespace Ui {
class tip_;
}

class tip_ : public QWidget
{
    Q_OBJECT

public:
    explicit tip_(int num,QWidget *parent = nullptr);
    ~tip_();
    QTextBrowser *text=new QTextBrowser(this);

private:
    Ui::tip_ *ui;
};

#endif // TIP__H
