#ifndef AREAC_H
#define AREAC_H

#include <QWidget>
#include<QLabel>
namespace Ui {
class AreaC;
}

class AreaC : public QWidget
{
    Q_OBJECT

public:
    explicit AreaC(QWidget *parent = nullptr);
    ~AreaC();
signals:
    void back();//
private slots:
    void on_pushButton_clicked();

private:
    Ui::AreaC *ui;
};

#endif // AREAC_H
