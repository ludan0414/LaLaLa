#ifndef WIDGET_PAGE_H
#define WIDGET_PAGE_H

#include <QWidget>

namespace Ui {
class widget_page;
}

class widget_page : public QWidget
{
    Q_OBJECT

public:
    explicit widget_page(QWidget *parent = nullptr);
    ~widget_page();

private:
    Ui::widget_page *ui;
};

#endif // WIDGET_PAGE_H
