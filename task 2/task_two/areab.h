#ifndef AREAB_H
#define AREAB_H

#include <QWidget>
#include<QLabel>
namespace Ui {
class AreaB;
}

class AreaB : public QWidget
{
    Q_OBJECT

public:
    explicit AreaB(QWidget *parent = nullptr);
    ~AreaB();
signals:
    void back();//
private slots:
    void on_pushButton_clicked();

private:
    Ui::AreaB *ui;
};

#endif // AREAB_H
