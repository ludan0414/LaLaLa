#ifndef AREAD_H
#define AREAD_H

#include <QWidget>
#include<QLabel>
namespace Ui {
class AreaD;
}

class AreaD : public QWidget
{
    Q_OBJECT

public:
    explicit AreaD(QWidget *parent = nullptr);
    ~AreaD();
signals:
    void back();//
private slots:
    void on_pushButton_clicked();

private:
    Ui::AreaD *ui;
};

#endif // AREAD_H
