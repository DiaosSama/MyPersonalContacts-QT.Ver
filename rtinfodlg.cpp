#include "rtinfodlg.h"
#include "ui_rtinfodlg.h"
#include"myhead.h"

RtInfoDlg::RtInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RtInfoDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("新建联系人"));
    //限制输入格式
    QRegExp regx("[a-zA-Z0-9.@]+$");
    QValidator *validator=new QRegExpValidator(regx);
    ui->namelineEdit->setValidator(validator);
    ui->generationlineEdit->setValidator(validator);
    ui->calllineEdit->setValidator(validator);
    ui->emaillineEdit->setValidator(validator);
    ui->birthyearlineEdit->setValidator(new QIntValidator(1,9999));
    ui->birthmonthlineEdit->setValidator(new QIntValidator(1,12));
    ui->birthdaylineEdit->setValidator(new QIntValidator(1,31));
}

RtInfoDlg::~RtInfoDlg()
{
    delete ui;
}

void RtInfoDlg::on_yesBtn_clicked()
{
    if((ui->namelineEdit->text()).isEmpty()||(ui->birthyearlineEdit->text()).isEmpty()||(ui->birthmonthlineEdit->text()).isEmpty()||(ui->birthdaylineEdit->text()).isEmpty())
    {
        QMessageBox::warning(this,tr("警告"),tr("姓名/生日输入不能为空！"),QMessageBox::Yes);
    }
    else
    {
        string name,generation,call,email;
        char *p,*q,*r,*s;
        int y,m,d;
        name=(ui->namelineEdit->text()).toStdString();
        generation=(ui->generationlineEdit->text()).toStdString();
        call=(ui->calllineEdit->text()).toStdString();
        email=(ui->emaillineEdit->text()).toStdString();
        y=(ui->birthyearlineEdit->text()).toInt();
        m=(ui->birthmonthlineEdit->text()).toInt();
        d=(ui->birthdaylineEdit->text()).toInt();
        p=Copy(p,name); q=Copy(q,generation); r=Copy(r,call); s=Copy(s,email);
        Relative a(p,y,m,d,r,s,q);
        a.Write();
        QMessageBox::warning(this,tr("提示"),tr("新建联系人成功！"),QMessageBox::Yes);
        accept();
    }
}
