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
    QPushButton *nextpage=new QPushButton(this);
    QPushButton *over=new QPushButton(this);
    QRadioButton *A=new QRadioButton(this);
    QRadioButton *B=new QRadioButton(this);
    QRadioButton *C=new QRadioButton(this);
    QRadioButton *D=new QRadioButton(this);
    QTextEdit *q=new QTextEdit(this);
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
    int wrongnum=0;
    int num=0;
    int number;
    QTimer *timer;
    QTime *TimeRecord;
    QLCDNumber *Time;
    QTimer flash;
    QStringList data;
    void updatetime();
    static bool visible;
    void writecsv(const QString& filename,  QStringList data);
    void readcsv(const QString& filename);

private slots:
    void switchpage(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
    void handleflash();
signals:
    void pagechanged(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
    void timeup();
    void flashtime();
private:
    Ui::page3 *ui;
};

#endif // PAGE3_H
