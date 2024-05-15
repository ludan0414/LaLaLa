#ifndef FUNCTIONWIDGET_H
#define FUNCTIONWIDGET_H

#include <QWidget>

namespace Ui {
class functionwidget;
}

class functionwidget : public QWidget
{
    Q_OBJECT

public:
    explicit functionwidget(QWidget *parent = nullptr);
    ~functionwidget();

private:
    Ui::functionwidget *ui;
};

#endif // FUNCTIONWIDGET_H
