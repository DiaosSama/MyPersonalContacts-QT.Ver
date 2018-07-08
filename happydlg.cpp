#include "happydlg.h"
#include "ui_happydlg.h"
#include"myhead.h"
#include<ctime>
#include<fstream>

HappyDlg::HappyDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HappyDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("生日祝贺"));
    ui->happyBtn->setEnabled(false);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char an[30],as[30],ac[30],ae[30];
    int y,m,d;
    fstream stuf; int work = 0;
    stuf.open("AddressBook1.txt", ios::in);
    if (!stuf)
    {
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (JudgeFiveDay(m, d))
        {
            Temp a(an,y,m,d,ac,ae,as);
            int size=ui->classmatetable->rowCount();
            ui->classmatetable->insertRow(size);
            ui->classmatetable->setItem(size,0,new QTableWidgetItem(a.GetName()));
            ui->classmatetable->setItem(size,1,new QTableWidgetItem(a.GetBirth()));
            ui->classmatetable->setItem(size,2,new QTableWidgetItem(CaculateWeekDay(1900 + ltm->tm_year,a.GetMonth(),a.GetDay())));
            work = 1;
        }
    }
    stuf.close();
    stuf.open("AddressBook2.txt", ios::in);
    if (!stuf)
    {
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (JudgeFiveDay(m, d))
        {
            Temp a(an,y,m,d,ac,ae,as);
            int size=ui->classmatetable->rowCount();
            ui->classmatetable->insertRow(size);
            ui->classmatetable->setItem(size,0,new QTableWidgetItem(a.GetName()));
            ui->classmatetable->setItem(size,1,new QTableWidgetItem(a.GetBirth()));
            ui->classmatetable->setItem(size,2,new QTableWidgetItem(CaculateWeekDay(1900 + ltm->tm_year,a.GetMonth(),a.GetDay())));
            work = 1;
        }
    }
    stuf.close();
    stuf.open("AddressBook3.txt", ios::in);
    if (!stuf)
    {
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (JudgeFiveDay(m, d))
        {
            Temp a(an,y,m,d,ac,ae,as);
            int size=ui->classmatetable->rowCount();
            ui->classmatetable->insertRow(size);
            ui->classmatetable->setItem(size,0,new QTableWidgetItem(a.GetName()));
            ui->classmatetable->setItem(size,1,new QTableWidgetItem(a.GetBirth()));
            ui->classmatetable->setItem(size,2,new QTableWidgetItem(CaculateWeekDay(1900 + ltm->tm_year,a.GetMonth(),a.GetDay())));
            work = 1;
        }
    }
    stuf.close();
    stuf.open("AddressBook4.txt", ios::in);
    if (!stuf)
    {
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        if (JudgeFiveDay(m, d))
        {
            Temp a(an,y,m,d,ac,ae,as);
            int size=ui->classmatetable->rowCount();
            ui->classmatetable->insertRow(size);
            ui->classmatetable->setItem(size,0,new QTableWidgetItem(a.GetName()));
            ui->classmatetable->setItem(size,1,new QTableWidgetItem(a.GetBirth()));
            ui->classmatetable->setItem(size,2,new QTableWidgetItem(CaculateWeekDay(1900 + ltm->tm_year,a.GetMonth(),a.GetDay())));
            work = 1;
        }
    }
    stuf.close();
    if (!work)
    {
        QMessageBox::warning(this,tr("提示"),tr("五天内没有联系人生日！"),QMessageBox::Yes);
    }
}

HappyDlg::~HappyDlg()
{
    delete ui;
}

void HappyDlg::on_happyBtn_clicked()
{
    edlg=new EmailDlg(this);
    edlg->exec();
}

void HappyDlg::on_classmatetable_itemClicked(QTableWidgetItem *item)
{
    name=ui->classmatetable->item(item->row(),0)->text();
    ui->happyBtn->setEnabled(true);
}
