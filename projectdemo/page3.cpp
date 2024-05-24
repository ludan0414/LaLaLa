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
#include<QRandomGenerator>
#include<Qlabel>
#include "tip_.h"
bool page3::visible = true;
page3::page3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::page3)
{
    ui->setupUi(this);
    this->resize(500,350);
    data<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n"<<"FALSE\n";
    timer = new QTimer(this);
    TimeRecord = new QTime(0, 1, 0); // 初始化 QTime 为 00:01:00
    Time = new QLCDNumber(this);
    Time->setDigitCount(8);
    Time->setStyleSheet("QLCDNumber { background-color: black; }");
    Time->setStyleSheet("background:black;color:#00ccff;");
    Time->display(TimeRecord->toString("mm:ss"));
    connect(timer, &QTimer::timeout, this, &page3::updatetime);
    timer->start(1000);
    rightnum=0;
    wrongnum=0;
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
    qDebug()<<n;
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
            else
                wrongnum++;
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
            else
                wrongnum++;
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
            else
                wrongnum++;
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
            else
                wrongnum++;
            emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
        }
    });
    connect(nextpage, &QPushButton::clicked, this, [&]() {
        emit pagechanged(this->flaga,this->flagb,this->flagc,this->flagd,this->correctanswer,this->reason,this->n); // 传递参数给信号
    });
    connect(this, &page3::pagechanged, this, &page3::switchpage);

    connect(over,&QPushButton::clicked,this,[&](){
        this->close();
        if(rightnum>=10)
            data[3]="TRUE\n";
        else if(rightnum>=20)
        {
            data[3]="TRUE\n";
            data[4]="TRUE\n";
        }
        else if(wrongnum==0&&rightnum>=30)
        {
            data[3]="TRUE\n";
            data[4]="TRUE\n";
            data[5]="TRUE\n";
        }
        else if(rightnum==0)
            data[8]="TRUE\n";
        writecsv("achievement.csv",data);
        tip_ *tips=new tip_(rightnum);
        tips->show();
    });
    connect(this, &page3::timeup, this, [&]() {
        this->close();
        if(rightnum>=10)
            data[3]="TRUE\n";
        else if(rightnum>=20)
        {
            data[3]="TRUE\n";
            data[4]="TRUE\n";
        }
        else if(wrongnum==0&&rightnum>=30)
        {
            data[3]="TRUE\n";
            data[4]="TRUE\n";
            data[5]="TRUE\n";
        }
        else if(rightnum==0)
            data[8]="TRUE\n";
        writecsv("achievement.csv",data);
        tip_ *tips=new tip_(rightnum);
        tips->show();
    });
    connect(&flash, &QTimer::timeout, this, &page3::handleflash);
    connect(this, &page3::flashtime, this, &page3::handleflash);
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
    int secondsLeft = QTime(0, 0).secsTo(*TimeRecord);
    if (secondsLeft== 0) {
        //qDebug()<<"haha";
        timer->stop();// 停止计时器
        flash.stop();
        this->close();
        over->setVisible(false);
        nextpage->setVisible(false);
        Time->setVisible(true);
        emit timeup();
    }
    else {
        if(secondsLeft == 5)
        {
            //qDebug()<<"haha";
            emit flashtime();
        }
        *TimeRecord = TimeRecord->addSecs(-1);
        Time->display(TimeRecord->toString("mm:ss"));
    }
}
void page3::handleflash()
{
    if (!flash.isActive()) {
        flash.start(100); // 启动闪烁定时器
    }
    //qDebug() << visible;
    QPalette palette = Time->palette();
    if (visible) {
        Time->setStyleSheet("background:red;");
    } else {
        Time->setStyleSheet("background:black;");
    }
    Time->setPalette(palette);
    visible = !visible; // 切换可见性
}
void page3::writecsv(const QString& filename,  QStringList data) {
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
