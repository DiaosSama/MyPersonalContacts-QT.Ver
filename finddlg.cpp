#include "finddlg.h"
#include "ui_finddlg.h"
#include"myhead.h"
#include<QDebug>

FindDlg::FindDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("搜索"));
    QRegExp regx("[a-zA-Z0-9.@]+$");
    QValidator *validator=new QRegExpValidator(regx);
    ui->namelineEdit->setValidator(validator);
}

FindDlg::~FindDlg()
{
    delete ui;
}

void FindDlg::on_findBtn_clicked()
{
    string name; char *p;
    name=(ui->namelineEdit->text()).toStdString();
    p=Copy(p,name);
    Temp x=SearchName_s(p);
    if(x.GetFlag()==0)
    {
        QMessageBox::warning(this,tr("提示"),tr("未能找到联系人！"),QMessageBox::Yes);
    }
    if(x.GetFlag()==1)
    {
        ui->namelb->setText("名字    ："); ui->namelb_2->setText(x.GetName());
        ui->infolb->setText("学校    ："); ui->infolb_2->setText(x.GetInfo());
        ui->birthlb->setText("生日    ：");ui->birthlb_2->setText(x.GetBirth());
        ui->calllb->setText("电话    ："); ui->calllb_2->setText(x.GetCall());
        ui->emaillb->setText("电子邮箱："); ui->emaillb_2->setText(x.GetEmail());
    }
    if(x.GetFlag()==2)
    {
        ui->namelb->setText("名字    ："); ui->namelb_2->setText(x.GetName());
        ui->infolb->setText("公司    ："); ui->infolb_2->setText(x.GetInfo());
        ui->birthlb->setText("生日    ：");ui->birthlb_2->setText(x.GetBirth());
        ui->calllb->setText("电话    ："); ui->calllb_2->setText(x.GetCall());
        ui->emaillb->setText("电子邮箱："); ui->emaillb_2->setText(x.GetEmail());
    }
    if(x.GetFlag()==3)
    {
        ui->namelb->setText("名字    ："); ui->namelb_2->setText(x.GetName());
        ui->infolb->setText("相遇地点："); ui->infolb_2->setText(x.GetInfo());
        ui->birthlb->setText("生日    ：");ui->birthlb_2->setText(x.GetBirth());
        ui->calllb->setText("电话    ："); ui->calllb_2->setText(x.GetCall());
        ui->emaillb->setText("电子邮箱："); ui->emaillb_2->setText(x.GetEmail());
    }
    if(x.GetFlag()==4)
    {
        ui->namelb->setText("名字    ："); ui->namelb_2->setText(x.GetName());
        ui->infolb->setText("关系    ："); ui->infolb_2->setText(x.GetInfo());
        ui->birthlb->setText("生日    ：");ui->birthlb_2->setText(x.GetBirth());
        ui->calllb->setText("电话    ："); ui->calllb_2->setText(x.GetCall());
        ui->emaillb->setText("电子邮箱："); ui->emaillb_2->setText(x.GetEmail());
    }
}
