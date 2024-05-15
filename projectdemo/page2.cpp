#include "page2.h"
#include "ui_page2.h"
#include "tip.h"
#include<QTime>
#include<QFile>
#include<QDebug>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QDialog>
page2::page2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page2)
{
    ui->setupUi(this);
    nextpage->setParent(this);
    nextpage->setText("next page");
    over->setParent(this);
    over->setText("显示答案");
    A->setParent(this);
    B->setParent(this);
    C->setParent(this);
    D->setParent(this);
    q->setParent(this);
    QFile inFile("QandA.csv");
    //QStringList lines;
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
    this->n= rand() % 70;    //产生70以内的随机数
    question=lines.at((n-1)*8);
    answerA=lines.at((n-1)*8+1);
    answerB=lines.at((n-1)*8+2);
    answerC=lines.at((n-1)*8+3);
    answerD=lines.at((n-1)*8+4);
    correctanswer=lines.at((n-1)*8+5);
    reason=lines.at((n-1)*8+6);
    q->setText(question);
    A->setText(answerA);
    B->setText(answerB);
    C->setText(answerC);
    D->setText(answerD);
    QVBoxLayout *layout1=new QVBoxLayout;
    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(nextpage);
    layout2->addWidget(over);
    layout1->addWidget(q);
    layout1->addWidget(A);
    layout1->addWidget(B);
    layout1->addWidget(C);
    layout1->addWidget(D);
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
    });
    connect(B, &QRadioButton::clicked, this,[&]() {
        this->flagb=!this->flagb;
        haschosed=true;
    });
    connect(C, &QRadioButton::clicked, this,[&]() {
        this->flagc=!this->flagc;
        haschosed=true;
    });
    connect(D, &QRadioButton::clicked, this,[&]() {
        this->flagd=!this->flagd;
        haschosed=true;
    });
    connect(nextpage, &QPushButton::clicked, this, [=]() {
        // 发射带参数的信号
        emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
    });
    connect(this, &page2::pagechanged, this, &page2::switchpage);

    connect(over,&QPushButton::clicked,this,[&](){
        if(haschosed)
        {
            if(this->correctanswer=="A")
            {
                if(flaga)
                {
                    this->q->setText("回答正确");
                }
                else
                {
                    this->q->setText("回答错误，原因如下："+this->reason);
                }
            }
            else if(this->correctanswer=="B")
            {
                if(flagb)
                {
                    this->q->setText("回答正确");
                }
                else
                {
                    this->q->setText("回答错误，原因如下："+this->reason);
                }
            }
            else if(this->correctanswer=="C")
            {
                if(flagc)
                {
                    this->q->setText("回答正确");
                }
                else
                {
                    this->q->setText("回答错误，原因如下："+this->reason);
                }
            }
            else if(this->correctanswer=="D")
            {
                if(flagd)
                {
                    this->q->setText("回答正确");
                }
                else
                {
                    this->q->setText("回答错误，原因如下:"+this->reason);
                }
            }
        }
    });
}

page2::~page2()
{
    delete ui;
}


void page2::switchpage(bool flaga,bool flagb,bool flagc,bool flagd,QString s,QString r,int n_)
{
    if(!haschosed)
    {
        tip *tips=new tip;
        tips->show();
    }
    else
    {
        if(flaga||flagb||flagc||flagd)
        {
            n++;
            q->setText(lines.at((n-1)*8));
            A->setText(lines.at((n-1)*8+1));
            B->setText(lines.at((n-1)*8+2));
            C->setText(lines.at((n-1)*8+3));
            D->setText(lines.at((n-1)*8+4));
            correctanswer=lines.at((n-1)*8+5);
            reason=lines.at((n-1)*8+6);
            A->setAutoExclusive(false);
            A->setChecked(false);
            A->setAutoExclusive(true);
            B->setAutoExclusive(false);
            B->setChecked(false);
            B->setAutoExclusive(true);
            C->setAutoExclusive(false);
            C->setChecked(false);
            C->setAutoExclusive(true);
            D->setAutoExclusive(false);
            D->setChecked(false);
            D->setAutoExclusive(true);
        }
    }
}
