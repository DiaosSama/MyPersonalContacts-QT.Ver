#include "cmeditdlg.h"
#include "ui_cmeditdlg.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"myhead.h"
#include<qDebug>

CmEditDlg::CmEditDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CmEditDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("编辑联系人"));
    MainWindow *ptr=(MainWindow*)parentWidget();
    string name; char *p; Temp x;
    //初始化窗口信息
    name=ptr->n;
    p=Copy(p,name);
    x=SearchName_s(p);
    ui->namelineEdit->setText(x.GetName());
    ui->schoollineEdit->setText(x.GetInfo());
    ui->calllineEdit->setText(x.GetCall());
    ui->emaillineEdit->setText(x.GetEmail());
    ui->birthyearlineEdit->setText(QString::number(x.GetYear(),10));
    ui->birthmonthlineEdit->setText(QString::number(x.GetMonth(),10));
    ui->birthdaylineEdit->setText(QString::number(x.GetDay(),10));
    //限制输入格式
    QRegExp regx("[a-zA-Z0-9.@]+$");
    QValidator *validator=new QRegExpValidator(regx);
    ui->namelineEdit->setValidator(validator);
    ui->schoollineEdit->setValidator(validator);
    ui->calllineEdit->setValidator(validator);
    ui->emaillineEdit->setValidator(validator);
    ui->birthyearlineEdit->setValidator(new QIntValidator(1,9999));
    ui->birthmonthlineEdit->setValidator(new QIntValidator(1,12));
    ui->birthdaylineEdit->setValidator(new QIntValidator(1,31));
}

CmEditDlg::~CmEditDlg()
{
    delete ui;
}

void CmEditDlg::on_yesBtn_clicked()
{
    //编辑保存信息
    if(QMessageBox::information(this,tr("提示"),tr("确定要更改该联系人的信息吗？"),QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
    {
            string name,school,call,email; char *p,*q,*r,*s;
            int y,m,d;
            name=(ui->namelineEdit->text()).toStdString();
            school=(ui->schoollineEdit->text()).toStdString();
            call=(ui->calllineEdit->text()).toStdString();
            email=(ui->emaillineEdit->text()).toStdString();
            y=(ui->birthyearlineEdit->text()).toInt();
            m=(ui->birthmonthlineEdit->text()).toInt();
            d=(ui->birthdaylineEdit->text()).toInt();
            p=Copy(p,name); q=Copy(q,school); r=Copy(r,call); s=Copy(s,email);
            Temp a(p,y,m,d,r,s,q);
            Edit_s(a);
            accept();
    }
}
