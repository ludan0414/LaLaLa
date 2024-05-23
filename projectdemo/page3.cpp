#include "page3.h"
#include "ui_page3.h"
#include<QTime>
#include<QFile>
#include<QDebug>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QDialog>
#include<QTime>
#include<QTimer>
#include<Qlabel>
#include "tip_.h"
page3::page3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page3)
{
    ui->setupUi(this);
    this->resize(500,350);
    timer = new QTimer(this);
    TimeRecord = new QTime(0, 0, 5); // 初始化 QTime 为 00:01:00
    Time = new QLCDNumber(this);
    Time->setDigitCount(8);
     Time->display(TimeRecord->toString("mm:ss"));
    connect(timer, &QTimer::timeout, this, &page3::updatetime);
    timer->start(1000);
    rightnum=0;
    num=0;
    number=3;
    nextpage->setParent(this);
    nextpage->setText("跳过本题");
    over->setParent(this);
    over->setText("结束挑战");
    A->setParent(this);
    B->setParent(this);
    C->setParent(this);
    D->setParent(this);
    q->setParent(this);
    QFile inFile("QandA.csv");
    int num=0;
    if (inFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream_text(&inFile);
        while (!stream_text.atEnd())
        {
            lines.push_back(stream_text.readLine());
        }
        inFile.close();
    }
    QTime time= QTime::currentTime();
    srand(time.msec()+time.second()*1000);
    this->n= rand()%40;    //产生40以内的随机数
    question=lines.at((n-1)*8);
    answerA=lines.at((n-1)*8+1);
    answerB=lines.at((n-1)*8+2);
    answerC=lines.at((n-1)*8+3);
    answerD=lines.at((n-1)*8+4);
    correctanswer=lines.at((n-1)*8+5);
    reason=lines.at((n-1)*8+6);
    q->setText(question);
    q->setReadOnly(true);
    A->setText(answerA);
    B->setText(answerB);
    C->setText(answerC);
    D->setText(answerD);
    QList<QRadioButton*> buttons = this->findChildren<QRadioButton*>();
    foreach (QRadioButton* button, buttons) {
        button->setStyleSheet("QRadioButton:pressed {background-color: rgb(0, 255, 0);}");
    }
    QVBoxLayout *layout1=new QVBoxLayout;
    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(nextpage);
    layout2->addWidget(over);
    layout1->addWidget(q);
    layout1->addWidget(A);
    layout1->addWidget(B);
    layout1->addWidget(C);
    layout1->addWidget(D);
    layout1->addWidget(Time);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    this->setLayout(layout);
    //layout2->setSizeConstraint(QLayout::SetFixedSize);
    this->flaga=false;
    this->flagb=false;
    this->flagc=false;
    this->flagd=false;
    this->haschosed=false;
    connect(A, &QRadioButton::clicked, this,[&]() {
        this->flaga=!this->flaga;
        haschosed=true;
        if(haschosed)
        {
            B->setEnabled(false);
            C->setEnabled(false);
            D->setEnabled(false);
            if(this->correctanswer=="A")
                rightnum++;
            emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
        }
    });
    connect(B, &QRadioButton::clicked, this,[&]() {
        this->flagb=!this->flagb;
        haschosed=true;
        if(haschosed)
        {
            A->setEnabled(false);
            C->setEnabled(false);
            D->setEnabled(false);
            if(this->correctanswer=="B")
                rightnum++;
            emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
        }
    });
    connect(C, &QRadioButton::clicked, this,[&]() {
        this->flagc=!this->flagc;
        haschosed=true;
        if(haschosed)
        {
            B->setEnabled(false);
            C->setEnabled(false);
            A->setEnabled(false);
            if(this->correctanswer=="C")
                rightnum++;
            emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
        }
    });
    connect(D, &QRadioButton::clicked, this,[&]() {
        this->flagd=!this->flagd;
        haschosed=true;
        if(haschosed)
        {
            B->setEnabled(false);
            C->setEnabled(false);
            A->setEnabled(false);
            if(this->correctanswer=="D")
                rightnum++;
            emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
        }
    });
    connect(nextpage, &QPushButton::clicked, this, [&]() {
        emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
    });
    connect(this, &page3::pagechanged, this, &page3::switchpage);

    connect(over,&QPushButton::clicked,this,[&](){
        tip_ *tips=new tip_(rightnum);
        tips->show();
    });
    connect(this, &page3::timeup, this, [&]() {
        tip_ *tips=new tip_(rightnum);
        tips->show();
    });
}

page3::~page3()
{
    delete ui;
}
void page3::switchpage(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_)
{
    this->flaga=false;
    this->flagb=false;
    this->flagc=false;
    this->flagd=false;
    this->haschosed=false;
    n++;
    q->setText(lines.at((n-1)*8));
    A->setText(lines.at((n-1)*8+1));
    B->setText(lines.at((n-1)*8+2));
    C->setText(lines.at((n-1)*8+3));
    D->setText(lines.at((n-1)*8+4));
    correctanswer=lines.at((n-1)*8+5);
    reason=lines.at((n-1)*8+6);
    QList<QRadioButton*> buttons = this->findChildren<QRadioButton*>();
    foreach (QRadioButton* button, buttons) {
        button->setEnabled(true);
        button->setAutoExclusive(false);
        button->setChecked(false);
        button->setAutoExclusive(true);
    }
}

void page3::updatetime()
{
    if (TimeRecord->secsTo(QTime(0, 0)) == 0) {
        timer->stop(); // 停止计时器
        over->setVisible(false);
        nextpage->setVisible(false);
        emit timeup();
    } else {
        *TimeRecord = TimeRecord->addSecs(-1);
        Time->display(TimeRecord->toString("mm:ss"));
    }
}
