#ifndef AREAA_H
#define AREAA_H

#include <QWidget>
#include<QLabel>

namespace Ui {
class AreaA;
}

class AreaA : public QWidget
{
    Q_OBJECT

public:
    explicit AreaA(QWidget *parent = nullptr);
    ~AreaA();

signals:
    void back();//

private slots:
    void on_pushButton_clicked();

private:
    Ui::AreaA *ui;
};

#endif // AREAA_H
