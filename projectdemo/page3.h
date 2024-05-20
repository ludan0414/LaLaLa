#ifndef PAGE3_H
#define PAGE3_H

#include <QWidget>
#include<QPushButton>
#include<qradiobutton.h>
#include<QTextEdit>
#include<QTime>
#include<QTimer>
#include<QLCDNumber>
namespace Ui {
class page3;
}

class page3 : public QWidget
{
    Q_OBJECT

public:
    explicit page3(QWidget *parent = nullptr);
    ~page3();
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
    int rightnum=0;
    int num=0;
    int number;
    QTimer *timer;
    QTime *TimeRecord;
    QLCDNumber *Time;
    void updatetime();

private slots:
    void switchpage(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
signals:
    void pagechanged(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
private:
    Ui::page3 *ui;
};

#endif // PAGE3_H
