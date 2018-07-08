#include "tminfodlg.h"
#include "ui_tminfodlg.h"
#include"myhead.h"

TmInfoDlg::TmInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TmInfoDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("新建联系人"));
    //限制输入格式
    QRegExp regx("[a-zA-Z0-9.@]+$");
    QValidator *validator=new QRegExpValidator(regx);
    ui->namelineEdit->setValidator(validator);
    ui->companylineEdit->setValidator(validator);
    ui->calllineEdit->setValidator(validator);
    ui->emaillineEdit->setValidator(validator);
    ui->birthyearlineEdit->setValidator(new QIntValidator(1,9999));
    ui->birthmonthlineEdit->setValidator(new QIntValidator(1,12));
    ui->birthdaylineEdit->setValidator(new QIntValidator(1,31));
}

TmInfoDlg::~TmInfoDlg()
{
    delete ui;
}

void TmInfoDlg::on_yesBtn_clicked()
{
    if((ui->namelineEdit->text()).isEmpty()||(ui->birthyearlineEdit->text()).isEmpty()||(ui->birthmonthlineEdit->text()).isEmpty()||(ui->birthdaylineEdit->text()).isEmpty())
    {
        QMessageBox::warning(this,tr("警告"),tr("姓名/生日输入不能为空！"),QMessageBox::Yes);
    }
    else
    {
        string name,company,call,email;
        char *p,*q,*r,*s;
        int y,m,d;
        name=(ui->namelineEdit->text()).toStdString();
        company=(ui->companylineEdit->text()).toStdString();
        call=(ui->calllineEdit->text()).toStdString();
        email=(ui->emaillineEdit->text()).toStdString();
        y=(ui->birthyearlineEdit->text()).toInt();
        m=(ui->birthmonthlineEdit->text()).toInt();
        d=(ui->birthdaylineEdit->text()).toInt();
        p=Copy(p,name); q=Copy(q,company); r=Copy(r,call); s=Copy(s,email);
        Teammate a(p,y,m,d,r,s,q);
        a.Write();
        QMessageBox::warning(this,tr("提示"),tr("新建联系人成功！"),QMessageBox::Yes);
        accept();
    }
}

