#include "dialog3.h"
#include "ui_dialog3.h"
#include <QFile>
#include<QDebug>
#include<QTime>
Dialog3::Dialog3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    QFile inFile("QandA.csv");
    QStringList lines;
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
    int n = rand() % 80;    //产生5以内的随机数
    QString question=lines.at((n-1)*8);
    QString answerA=lines.at((n-1)*8+1);
    QString answerB=lines.at((n-1)*8+2);
    QString answerC=lines.at((n-1)*8+3);
    QString answerD=lines.at((n-1)*8+4);
    QString correctanswer=lines.at((n-1)*8+5);
    QString reason=lines.at((n-1)*8+6);
    ui->textEdit->setText(question);
    //ui->radioButton->resize();
    ui->radioButton_2->setText(answerA);
    ui->radioButton_3->setText(answerB);
    ui->radioButton_4->setText(answerC);
    ui->radioButton_5->setText(answerD);
}

Dialog3::~Dialog3()
{
    delete ui;
}
