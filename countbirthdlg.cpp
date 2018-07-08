#include "countbirthdlg.h"
#include "ui_countbirthdlg.h"
#include"myhead.h"
#include<string>

CountBirthDlg::CountBirthDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CountBirthDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("各月份生日人数统计"));
    int *p=Birthmonth();
    string a="一月：    ", b=to_string(p[1]), c=" 人", d;
    d=a+b+c;
    ui->label_1->setText(QString::fromStdString(d));
    a="二月：    ", b=to_string(p[2]);
    d=a+b+c;
    ui->label_2->setText(QString::fromStdString(d));
    a="三月：    ", b=to_string(p[3]);
    d=a+b+c;
    ui->label_3->setText(QString::fromStdString(d));
    a="四月：    ", b=to_string(p[4]);
    d=a+b+c;
    ui->label_4->setText(QString::fromStdString(d));
    a="五月：    ", b=to_string(p[5]);
    d=a+b+c;
    ui->label_5->setText(QString::fromStdString(d));
    a="六月：    ", b=to_string(p[6]);
    d=a+b+c;
    ui->label_6->setText(QString::fromStdString(d));
    a="七月：    ", b=to_string(p[7]);
    d=a+b+c;
    ui->label_7->setText(QString::fromStdString(d));
    a="八月：    ", b=to_string(p[8]);
    d=a+b+c;
    ui->label_8->setText(QString::fromStdString(d));
    a="九月：    ", b=to_string(p[9]);
    d=a+b+c;
    ui->label_9->setText(QString::fromStdString(d));
    a="十月：    ", b=to_string(p[10]);
    d=a+b+c;
    ui->label_10->setText(QString::fromStdString(d));
    a="十一月：  ", b=to_string(p[11]);
    d=a+b+c;
    ui->label_11->setText(QString::fromStdString(d));
    a="十二月：  ", b=to_string(p[12]);
    d=a+b+c;
    ui->label_12->setText(QString::fromStdString(d));
    delete []p;
}

CountBirthDlg::~CountBirthDlg()
{
    delete ui;
}
