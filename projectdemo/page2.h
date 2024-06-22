#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>
#include<QPushButton>
#include<qradiobutton.h>
#include<QTextEdit>
#include<QLabel>
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
    QPushButton *nextpage=new QPushButton("下一题",this);
    QPushButton *over=new QPushButton("结束挑战",this);
    QLabel displaynum;
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
    QStringList data;
    int rightnum=0;
    int num=0;
    int number;
    int myanswer[11];
    bool newgrade;
    void writecsv(const QString& filename,  QStringList data);
    void readcsv(const QString& filename);
    void init();
    void addlayout();
    void connectRadioButton(QRadioButton *button);

private slots:
    void switchpage(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
signals:
    void pagechanged(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_);
private:
    Ui::page2 *ui;
};

#endif // PAGE2_H
