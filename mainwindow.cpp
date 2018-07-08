#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"myhead.h"
#include<QtWidgets>
#include<cstring>
#include<fstream>
#include<iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("个人通讯录管理系统"));
    dlg=new NewDlg(this);
    fnddlg=new FindDlg(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    flag=0; ui->deleteBtn->setEnabled(false);//设置删除按钮一开始不可用
    ui->editBtn->setEnabled(false);//设置编辑按钮一开始不可用
    //表格宽度自适应调整
    ui->classmatetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->teammatetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->friendtable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->relativetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    fstream stuf; char an[30],as[30],ac[30],ae[30]; int y,m,d;
    stuf.open("AddressBook1.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Classmate a(an,y,m,d,ac,ae,as);
        int size=ui->classmatetable->rowCount();
        ui->classmatetable->insertRow(size);
        ui->classmatetable->setItem(size,0,new QTableWidgetItem(a.GetName()));
        ui->classmatetable->setItem(size,1,new QTableWidgetItem(a.GetSchool()));
        ui->classmatetable->setItem(size,2,new QTableWidgetItem(a.GetBirth()));
        ui->classmatetable->setItem(size,3,new QTableWidgetItem(a.GetCall()));
        ui->classmatetable->setItem(size,4,new QTableWidgetItem(a.GetEmail()));
    }
    stuf.close();
    //初始化Teammate
    stuf.open("AddressBook2.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Teammate b(an,y,m,d,ac,ae,as);
        int size=ui->teammatetable->rowCount();
        ui->teammatetable->insertRow(size);
        ui->teammatetable->setItem(size,0,new QTableWidgetItem(b.GetName()));
        ui->teammatetable->setItem(size,1,new QTableWidgetItem(b.GetCompany()));
        ui->teammatetable->setItem(size,2,new QTableWidgetItem(b.GetBirth()));
        ui->teammatetable->setItem(size,3,new QTableWidgetItem(b.GetCall()));
        ui->teammatetable->setItem(size,4,new QTableWidgetItem(b.GetEmail()));
    }
    stuf.close();
    //初始化Friend
    stuf.open("AddressBook3.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Friend c(an,y,m,d,ac,ae,as);
        int size=ui->friendtable->rowCount();
        ui->friendtable->insertRow(size);
        ui->friendtable->setItem(size,0,new QTableWidgetItem(c.GetName()));
        ui->friendtable->setItem(size,1,new QTableWidgetItem(c.GetPlace()));
        ui->friendtable->setItem(size,2,new QTableWidgetItem(c.GetBirth()));
        ui->friendtable->setItem(size,3,new QTableWidgetItem(c.GetCall()));
        ui->friendtable->setItem(size,4,new QTableWidgetItem(c.GetEmail()));
    }
    stuf.close();
    //初始化Relative
    stuf.open("AddressBook4.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Relative e(an,y,m,d,ac,ae,as);
        int size=ui->relativetable->rowCount();
        ui->relativetable->insertRow(size);
        ui->relativetable->setItem(size,0,new QTableWidgetItem(e.GetName()));
        ui->relativetable->setItem(size,1,new QTableWidgetItem(e.GetGeneration()));
        ui->relativetable->setItem(size,2,new QTableWidgetItem(e.GetBirth()));
        ui->relativetable->setItem(size,3,new QTableWidgetItem(e.GetCall()));
        ui->relativetable->setItem(size,4,new QTableWidgetItem(e.GetEmail()));
    }
    stuf.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newBtn_clicked()
{
    hide();
    dlg->show();
    dlg->exec();
    Fresh();
    show();
}

void MainWindow::Fresh()
{
    flag=0; ui->deleteBtn->setEnabled(false);
    ui->editBtn->setEnabled(false);
    //清空表格
    ui->classmatetable->clearContents();
    ui->teammatetable->clearContents();
    ui->friendtable->clearContents();
    ui->relativetable->clearContents();
    int lenc=ui->classmatetable->rowCount();
    for(int i=0;i<lenc;i++)
    {
        ui->classmatetable->removeRow(0);
    }
    int lent=ui->teammatetable->rowCount();
    for(int i=0;i<lent;i++)
    {
        ui->teammatetable->removeRow(0);
    }
    int lenf=ui->friendtable->rowCount();
    for(int i=0;i<lenf;i++)
    {
        ui->friendtable->removeRow(0);
    }
    int lenr=ui->relativetable->rowCount();
    for(int i=0;i<lenr;i++)
    {
        ui->relativetable->removeRow(0);
    }
    ui->classmatetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->teammatetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->friendtable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->relativetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    fstream stuf; char an[30],as[30],ac[30],ae[30]; int y,m,d;
    stuf.open("AddressBook1.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Classmate a(an,y,m,d,ac,ae,as);
        int size=ui->classmatetable->rowCount();
        ui->classmatetable->insertRow(size);
        ui->classmatetable->setItem(size,0,new QTableWidgetItem(a.GetName()));
        ui->classmatetable->setItem(size,1,new QTableWidgetItem(a.GetSchool()));
        ui->classmatetable->setItem(size,2,new QTableWidgetItem(a.GetBirth()));
        ui->classmatetable->setItem(size,3,new QTableWidgetItem(a.GetCall()));
        ui->classmatetable->setItem(size,4,new QTableWidgetItem(a.GetEmail()));
    }
    stuf.close();
    //初始化Teammate
    stuf.open("AddressBook2.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Teammate b(an,y,m,d,ac,ae,as);
        int size=ui->teammatetable->rowCount();
        ui->teammatetable->insertRow(size);
        ui->teammatetable->setItem(size,0,new QTableWidgetItem(b.GetName()));
        ui->teammatetable->setItem(size,1,new QTableWidgetItem(b.GetCompany()));
        ui->teammatetable->setItem(size,2,new QTableWidgetItem(b.GetBirth()));
        ui->teammatetable->setItem(size,3,new QTableWidgetItem(b.GetCall()));
        ui->teammatetable->setItem(size,4,new QTableWidgetItem(b.GetEmail()));
    }
    stuf.close();
    //初始化Friend
    stuf.open("AddressBook3.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Friend c(an,y,m,d,ac,ae,as);
        int size=ui->friendtable->rowCount();
        ui->friendtable->insertRow(size);
        ui->friendtable->setItem(size,0,new QTableWidgetItem(c.GetName()));
        ui->friendtable->setItem(size,1,new QTableWidgetItem(c.GetPlace()));
        ui->friendtable->setItem(size,2,new QTableWidgetItem(c.GetBirth()));
        ui->friendtable->setItem(size,3,new QTableWidgetItem(c.GetCall()));
        ui->friendtable->setItem(size,4,new QTableWidgetItem(c.GetEmail()));
    }
    stuf.close();
    //初始化Relative
    stuf.open("AddressBook4.txt", ios::in);
    stuf.seekg(ios::beg);
    if (!stuf)
    {
        QMessageBox::warning(this,tr("警告！"),tr("程序出现异常！"),QMessageBox::Yes);
        abort();
    }
    while (stuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        Relative e(an,y,m,d,ac,ae,as);
        int size=ui->relativetable->rowCount();
        ui->relativetable->insertRow(size);
        ui->relativetable->setItem(size,0,new QTableWidgetItem(e.GetName()));
        ui->relativetable->setItem(size,1,new QTableWidgetItem(e.GetGeneration()));
        ui->relativetable->setItem(size,2,new QTableWidgetItem(e.GetBirth()));
        ui->relativetable->setItem(size,3,new QTableWidgetItem(e.GetCall()));
        ui->relativetable->setItem(size,4,new QTableWidgetItem(e.GetEmail()));
    }
    stuf.close();
}

void MainWindow::on_classmatetable_itemClicked(QTableWidgetItem *item)
{
    cur_row=item->row();
    n=(ui->classmatetable->item(cur_row,0)->text()).toStdString();
    flag=1;
    ui->deleteBtn->setEnabled(true);
    ui->editBtn->setEnabled(true);
}

void MainWindow::on_teammatetable_itemClicked(QTableWidgetItem *item)
{
    cur_row=item->row();
    n=(ui->teammatetable->item(cur_row,0)->text()).toStdString();
    flag=2;
    ui->deleteBtn->setEnabled(true);
    ui->editBtn->setEnabled(true);
}

void MainWindow::on_friendtable_itemClicked(QTableWidgetItem *item)
{
    cur_row=item->row();
    n=(ui->friendtable->item(cur_row,0)->text()).toStdString();
    flag=3;
    ui->deleteBtn->setEnabled(true);
    ui->editBtn->setEnabled(true);
}

void MainWindow::on_relativetable_itemClicked(QTableWidgetItem *item)
{
    cur_row=item->row();
    n=(ui->relativetable->item(cur_row,0)->text()).toStdString();
    flag=4;
    ui->deleteBtn->setEnabled(true);
    ui->editBtn->setEnabled(true);
}

void MainWindow::on_deleteBtn_clicked()
{
    if(QMessageBox::information(this,tr("提示"),tr("确定要删除该联系人吗？"),QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
    {
        if(flag==1)
        {
            string name; char *p;
            name=(ui->classmatetable->item(cur_row,0)->text()).toStdString();
            p=Copy(p,name);
            Delete(p);
            QMessageBox::warning(this,tr("提示"),tr("删除成功！"),QMessageBox::Yes);
            ui->classmatetable->removeRow(cur_row);
        }
        if(flag==2)
        {
            string name; char *p;
            name=(ui->teammatetable->item(cur_row,0)->text()).toStdString();
            p=Copy(p,name);
            Delete(p);
            QMessageBox::warning(this,tr("提示"),tr("删除成功！"),QMessageBox::Yes);
            ui->teammatetable->removeRow(cur_row);
        }
        if(flag==3)
        {
            string name; char *p;
            name=(ui->friendtable->item(cur_row,0)->text()).toStdString();
            p=Copy(p,name);
            Delete(p);
            QMessageBox::warning(this,tr("提示"),tr("删除成功！"),QMessageBox::Yes);
            ui->friendtable->removeRow(cur_row);
        }
        if(flag==4)
        {
            string name; char *p;
            name=(ui->relativetable->item(cur_row,0)->text()).toStdString();
            p=Copy(p,name);
            Delete(p);
            QMessageBox::warning(this,tr("提示"),tr("删除成功！"),QMessageBox::Yes);
            ui->relativetable->removeRow(cur_row);
        }
    }
}

void MainWindow::on_searchBtn_clicked()
{
    fnddlg->exec();
}

void MainWindow::on_editBtn_clicked()
{
    if(flag==1)
    {
        cmdlg=new CmEditDlg(this);
        cmdlg->exec();
        Fresh();
    }
    if(flag==2)
    {
        tmdlg=new TmEditDlg(this);
        tmdlg->exec();
        Fresh();
    }
    if(flag==3)
    {
        fddlg=new FdEditDlg(this);
        fddlg->exec();
        Fresh();
    }
    if(flag==4)
    {
        rtdlg=new RtEditDlg(this);
        rtdlg->exec();
        Fresh();
    }
}

void MainWindow::on_countbirthBtn_clicked()
{
    cbdlg=new CountBirthDlg(this);
    cbdlg->exec();
    Fresh();
}

void MainWindow::on_sortBtn_clicked()
{
    flag=0; ui->deleteBtn->setEnabled(false);
    ui->editBtn->setEnabled(false);
    //清空表格
    ui->classmatetable->clearContents();
    ui->teammatetable->clearContents();
    ui->friendtable->clearContents();
    ui->relativetable->clearContents();
    int lenc=ui->classmatetable->rowCount();
    for(int i=0;i<lenc;i++)
    {
        ui->classmatetable->removeRow(0);
    }
    int lent=ui->teammatetable->rowCount();
    for(int i=0;i<lent;i++)
    {
        ui->teammatetable->removeRow(0);
    }
    int lenf=ui->friendtable->rowCount();
    for(int i=0;i<lenf;i++)
    {
        ui->friendtable->removeRow(0);
    }
    int lenr=ui->relativetable->rowCount();
    for(int i=0;i<lenr;i++)
    {
        ui->relativetable->removeRow(0);
    }
    ui->classmatetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->teammatetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->friendtable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    ui->relativetable->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);

    char **p; int now = 0; char *temp = new char[30]; int work;
    char an[30],as[30],ac[30],ae[30]; int y,m,d;

    fstream instuf;
    p = new char *[lenc];
    for (int j = 0;j < lenc;j++)
    {
        p[j] = new char[30];
    }
    instuf.open("AddressBook1.txt", ios::in);
    while (instuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        strcpy(p[now], an);
        now++;
    }
    instuf.close();
    //名字放置数组中排序
    for (int j = 1;j < lenc;j++)
    {
        work = 1;
        for (int k = 0;k < lenc-j;k++)
        {
            if (strcmp(p[k], p[k + 1]) > 0)
            {
                strcpy(temp, p[k]);
                strcpy(p[k], p[k + 1]);
                strcpy(p[k + 1], temp);
                work = 0;
            }
        }
        if (work) break;
    }
    for (int j = 0;j < lenc;j++)
    {
        Temp a=SearchName_s(p[j]);
        int s=ui->classmatetable->rowCount();
        ui->classmatetable->insertRow(s);
        ui->classmatetable->setItem(s,0,new QTableWidgetItem(a.GetName()));
        ui->classmatetable->setItem(s,1,new QTableWidgetItem(a.GetInfo()));
        ui->classmatetable->setItem(s,2,new QTableWidgetItem(a.GetBirth()));
        ui->classmatetable->setItem(s,3,new QTableWidgetItem(a.GetCall()));
        ui->classmatetable->setItem(s,4,new QTableWidgetItem(a.GetEmail()));
    }
    now=0; delete []p;

    p = new char *[lent];
    for (int j = 0;j < lent;j++)
    {
        p[j] = new char[30];
    }
    instuf.open("AddressBook2.txt", ios::in);
    while (instuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        strcpy(p[now], an);
        now++;
    }
    instuf.close();
    //名字放置数组中排序
    for (int j = 1;j < lent;j++)
    {
        work = 1;
        for (int k = 0;k < lent-j;k++)
        {
            if (strcmp(p[k], p[k + 1]) > 0)
            {
                strcpy(temp, p[k]);
                strcpy(p[k], p[k + 1]);
                strcpy(p[k + 1], temp);
                work = 0;
            }
        }
        if (work) break;
    }
    for (int j = 0;j < lent;j++)
    {
        Temp a=SearchName_s(p[j]);
        int s=ui->teammatetable->rowCount();
        ui->teammatetable->insertRow(s);
        ui->teammatetable->setItem(s,0,new QTableWidgetItem(a.GetName()));
        ui->teammatetable->setItem(s,1,new QTableWidgetItem(a.GetInfo()));
        ui->teammatetable->setItem(s,2,new QTableWidgetItem(a.GetBirth()));
        ui->teammatetable->setItem(s,3,new QTableWidgetItem(a.GetCall()));
        ui->teammatetable->setItem(s,4,new QTableWidgetItem(a.GetEmail()));
    }
    now=0; delete []p;

    p = new char *[lenf];
    for (int j = 0;j < lenf;j++)
    {
        p[j] = new char[30];
    }
    instuf.open("AddressBook3.txt", ios::in);
    while (instuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        strcpy(p[now], an);
        now++;
    }
    instuf.close();
    //名字放置数组中排序
    for (int j = 1;j < lenf;j++)
    {
        work = 1;
        for (int k = 0;k < lenf-j;k++)
        {
            if (strcmp(p[k], p[k + 1]) > 0)
            {
                strcpy(temp, p[k]);
                strcpy(p[k], p[k + 1]);
                strcpy(p[k + 1], temp);
                work = 0;
            }
        }
        if (work) break;
    }
    for (int j = 0;j < lenf;j++)
    {
        Temp a=SearchName_s(p[j]);
        int s=ui->friendtable->rowCount();
        ui->friendtable->insertRow(s);
        ui->friendtable->setItem(s,0,new QTableWidgetItem(a.GetName()));
        ui->friendtable->setItem(s,1,new QTableWidgetItem(a.GetInfo()));
        ui->friendtable->setItem(s,2,new QTableWidgetItem(a.GetBirth()));
        ui->friendtable->setItem(s,3,new QTableWidgetItem(a.GetCall()));
        ui->friendtable->setItem(s,4,new QTableWidgetItem(a.GetEmail()));
    }
    now=0; delete []p;

    p = new char *[lenr];
    for (int j = 0;j < lenr;j++)
    {
        p[j] = new char[30];
    }
    instuf.open("AddressBook4.txt", ios::in);
    while (instuf >> an >> as >> y >> m >> d >> ac >> ae)
    {
        strcpy(p[now], an);
        now++;
    }
    instuf.close();
    //名字放置数组中排序
    for (int j = 1;j < lenr;j++)
    {
        work = 1;
        for (int k = 0;k < lenr-j;k++)
        {
            if (strcmp(p[k], p[k + 1]) > 0)
            {
                strcpy(temp, p[k]);
                strcpy(p[k], p[k + 1]);
                strcpy(p[k + 1], temp);
                work = 0;
            }
        }
        if (work) break;
    }
    for (int j = 0;j < lenr;j++)
    {
        Temp a=SearchName_s(p[j]);
        int s=ui->relativetable->rowCount();
        ui->relativetable->insertRow(s);
        ui->relativetable->setItem(s,0,new QTableWidgetItem(a.GetName()));
        ui->relativetable->setItem(s,1,new QTableWidgetItem(a.GetInfo()));
        ui->relativetable->setItem(s,2,new QTableWidgetItem(a.GetBirth()));
        ui->relativetable->setItem(s,3,new QTableWidgetItem(a.GetCall()));
        ui->relativetable->setItem(s,4,new QTableWidgetItem(a.GetEmail()));
    }
    now=0; delete []p;
}

void MainWindow::on_happyBtn_clicked()
{
    hpdlg=new HappyDlg(this);
    hpdlg->exec();
}
