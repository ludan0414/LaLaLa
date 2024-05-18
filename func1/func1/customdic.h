#ifndef CUSTOMDIC_H
#define CUSTOMDIC_H

#include <QWidget>

namespace Ui {
class customdic;
}

class customdic : public QWidget
{
    Q_OBJECT

public:
    explicit customdic(QWidget *parent = nullptr);
    ~customdic();

private:
    Ui::customdic *ui;
};

#endif // CUSTOMDIC_H
