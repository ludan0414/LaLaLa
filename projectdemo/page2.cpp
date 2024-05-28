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
    setWindowTitle("标准模式");
    this->resize(500,350);
    init();
    displaynum.setParent(this);
    displaynum.setText(QString("%1/%2").arg(num+1).arg(10));
    displaynum.setMaximumHeight(10);
    displaynum.setStyleSheet("font-size: 12px; font-weight: bold;");
    q->setStyleSheet("QTextEdit { background-color: rgba(132, 112, 255, 15); }");
    q->setStyleSheet(q->styleSheet() + " QTextEdit { color: black; font-size: 13pt; font-weight: bold; font-style: italic; }");
    q->setMaximumHeight(100);
    over->setMinimumHeight(30);
    nextpage->setMinimumHeight(30);
    QFont font("Arial", 12);
    QList<QRadioButton*> buttons = this->findChildren<QRadioButton*>();
    foreach (QRadioButton* button, buttons) {
        button->setStyleSheet("QRadioButton:pressed {background-color: rgb(0, 191, 255);}");
        button->setMinimumHeight(20);
        button->setFont(font);
    }
    addlayout();
    readcsv("achievement.csv");
    connectRadioButton(A);
    connectRadioButton(B);
    connectRadioButton(C);
    connectRadioButton(D);
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
        if(rightnum>=5)
            data[1]="TRUE\n";
        if(rightnum==10)
            data[2]="TRUE\n";
        if(rightnum==0)
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
void page2::readcsv(const QString& filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream_text(&file);
        while (!stream_text.atEnd())
        {
            QString line = stream_text.readLine();
            line.append("\n"); // 添加换行符
            data.append(line);
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
        displaynum.setText(QString("%1/%2").arg(num+1).arg(10));
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
void page2::init()
{
    rightnum=0;number=2;num=0;
    for(int i=0;i<10;i++)
        myanswer[i]=0;
    this->flaga=false;this->flagb=false;this->flagc=false;this->flagd=false;this->haschosed=false;
    QFile inFile("QandA.csv");
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
    this->n= rand()%70;
    if(n==0)
        n++;    //产生70以内的随机数
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
}
void page2::addlayout()
{
    QVBoxLayout *layout1=new QVBoxLayout;
    QHBoxLayout *layout2=new QHBoxLayout;
    layout2->addWidget(nextpage);
    layout2->addWidget(over);
    layout1->addWidget(&displaynum);
    layout1->addSpacing(7);
    layout1->addWidget(q);
    layout1->addSpacing(10);
    layout1->addWidget(A);
    layout1->addSpacing(10);
    layout1->addWidget(B);
    layout1->addSpacing(10);
    layout1->addWidget(C);
    layout1->addSpacing(10);
    layout1->addWidget(D);
    layout1->setSpacing(0);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(layout1);
    layout->addLayout(layout2);
    layout->setSpacing(10);
    this->setLayout(layout);
}
void page2::connectRadioButton(QRadioButton *button) {
    connect(button, &QRadioButton::clicked, this, [=]() {
        if(haschosed)return;
        haschosed = true;
        QString userAnswer;
        if (button == A) {
            B->setEnabled(false);C->setEnabled(false);D->setEnabled(false);
            userAnswer = "A";
        } else if (button == B) {
            A->setEnabled(false);C->setEnabled(false);D->setEnabled(false);
            userAnswer = "B";
        } else if (button == C) {
            B->setEnabled(false);A->setEnabled(false);D->setEnabled(false);
            userAnswer = "C";
        } else if (button == D) {
            B->setEnabled(false);C->setEnabled(false);A->setEnabled(false);
            userAnswer = "D";
        }
        if (userAnswer == correctanswer) {
            rightnum++;
            q->setHtml("<span style='color: blue;'>回答正确</span>");
            myanswer[num] = 1;
        } else {
            q->setHtml("<span style='color: red;'>回答错误，正确答案为 " + correctanswer + "<br>原因如下：" + reason + "</span>");
        }
    });
}
