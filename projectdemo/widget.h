#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_comboBox_editTextChanged(const QString &arg1);

    void on_choosecity_editTextChanged(const QString &arg1);

    void on_entergarbage_textChanged();

    void on_choosecity_currentIndexChanged(int index);

    void on_confirm_clicked();

    void on_addgarbage_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
