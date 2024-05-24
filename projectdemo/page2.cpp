#include "page2.h"
#include "ui_page2.h"
#include "tip.h"
#include"tip_.h"
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
    this->resize(500,350);
    rightnum=0;
    number=2;
    num=0;
    for(int i=0;i<10;i++)
        myanswer[i]=0;
    nextpage->setParent(this);
    nextpage->setText("下一题");
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
    this->n= rand()%70;    //产生70以内的随机数
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
    data<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n";
    connect(A, &QRadioButton::clicked, this,[&]() {
        this->flaga=!this->flaga;
        haschosed=true;
        if(haschosed)
        {
            B->setEnabled(false);
            C->setEnabled(false);
            D->setEnabled(false);
            if(this->correctanswer=="A")
            {
                rightnum++;
                this->q->setText("回答正确");
                myanswer[num]=1;
            }
            else
                this->q->setText("回答错误，正确答案为"+this->correctanswer+"\n原因如下："+this->reason);
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
            {
                rightnum++;
                this->q->setText("回答正确");
                myanswer[num]=1;
            }
            else
                this->q->setText("回答错误，正确答案为"+this->correctanswer+"\n原因如下："+this->reason);
        }
    });
    connect(C, &QRadioButton::clicked, this,[&]() {
        this->flagc=!this->flagc;
        haschosed=true;
        if(haschosed)
        {
            B->setEnabled(false);
            A->setEnabled(false);
            D->setEnabled(false);
            if(this->correctanswer=="C")
            {
                rightnum++;
                this->q->setText("回答正确");
                myanswer[num]=1;
            }
            else
                this->q->setText("回答错误，正确答案为"+this->correctanswer+"\n原因如下："+this->reason);
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
            {
                rightnum++;
                this->q->setText("回答正确");
                myanswer[num]=1;
            }
            else
                this->q->setText("回答错误，正确答案为"+this->correctanswer+"\n原因如下："+this->reason);
        }
    });
    connect(nextpage, &QPushButton::clicked, this, [&]() {
        this->num++;
        if(this->num<10)
            emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
        else
        {
            nextpage->setVisible(false);
            over->setText("查看最终分数");
        }
    });
    connect(this, &page2::pagechanged, this, &page2::switchpage);

    connect(over,&QPushButton::clicked,this,[&](){
        this->close();
        if(rightnum>=3)
            data[0]="TRUE\n";
        else if(rightnum>=5)
        {
            data[0]="TRUE\n";
            data[1]="TRUE\n";
        }
        else if(rightnum==10)
        {
            data[0]="TRUE\n";
            data[1]="TRUE\n";
            data[2]="TRUE\n";
        }
        else if(rightnum==0)
            data[8]="TRUE\n";
        for(int i=0;i<=7;i++)
        {
            if(myanswer[i]==1&&myanswer[i+1]==1&&myanswer[i+2]==1)
            {
                data[6]="TRUE\n";
                break;
            }
        }
        for(int i=0;i<=5;i++)
        {
            if(myanswer[i]==1&&myanswer[i+1]==1&&myanswer[i+2]==1&&myanswer[i+3]==1&&myanswer[i+4]==1)
            {
                data[6]="TRUE\n";
                data[7]="TRUE\n";
                break;
            }
        }
        writecsv("achievement.csv",data);
        tip_ *tips=new tip_(rightnum);
        tips->show();
    });
}

page2::~page2()
{
    delete ui;
}

void page2::writecsv(const QString& filename,  QStringList data) {
    QFile file(filename);
    //以只写方式打开，完全重写数据
    if (file.open(QIODevice::WriteOnly))
    {
        for (int i = 0; i < data.size(); i++)
        {
            file.write(data[i].toStdString().c_str());/*写入每一行数据到文件*/
        }
        file.close();
    }
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
    }
}
