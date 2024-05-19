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

private slots:
    void on_new_2_clicked();

    void on_entername_textChanged();

    void on_change_clicked();

    void on_enterid_textChanged();

    void on_delete_2_clicked();

    void on_pushButton_clicked();

    void on_save_clicked();

private:
    Ui::customdic *ui;
};

#endif // CUSTOMDIC_H
