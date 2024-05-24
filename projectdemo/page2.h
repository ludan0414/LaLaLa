#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>
#include<QPushButton>
#include<qradiobutton.h>
#include<QTextEdit>
#include<qstring.h>
namespace Ui {
class page2;
}

class page2 : public QWidget
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = nullptr);
    ~page2();
private:
    QPushButton *nextpage=new QPushButton;
    QPushButton *over=new QPushButton;
    QRadioButton *A=new QRadioButton;
    QRadioButton *B=new QRadioButton;
    QRadioButton *C=new QRadioButton;
    QRadioButton *D=new QRadioButton;
    QTextEdit *q=new QTextEdit;
    QString correctanswer;
    QString reason;
    int n;//从0-70 第一道题的题号
    bool flaga;
    bool flagb;
    bool flagc;
    bool flagd;
    bool haschosed;
    QStringList lines;
    QString question;
    QString answerA;
    QString answerC;
    QString answerB;
    QString answerD;
    QStringList data;
    int rightnum=0;
    int num=0;
    int number;
    int myanswer[11];
    void writecsv(const QString& filename,  QStringList data);

private slots:
    void switchpage(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
signals:
    void pagechanged(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
private:
    Ui::page2 *ui;
};

#endif // PAGE2_H
