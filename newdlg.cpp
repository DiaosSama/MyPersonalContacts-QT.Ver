#include "newdlg.h"
#include "ui_newdlg.h"
#include"myhead.h"
#include<iostream>
using namespace std;

NewDlg::NewDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("新建联系人"));
}

NewDlg::~NewDlg()
{
    delete ui;
}

void NewDlg::on_classmateBtn_clicked()
{
   dlg=new CmInfoDlg(this);
   dlg->exec();
}

void NewDlg::on_teammateBtn_clicked()
{
    tmdlg=new TmInfoDlg(this);
    tmdlg->exec();
}

void NewDlg::on_friendBtn_clicked()
{
    FdInfoDlg *fddlg=new FdInfoDlg(this);
    fddlg->exec();
}

void NewDlg::on_relativeBtn_clicked()
{
    rtdlg=new RtInfoDlg(this);
    rtdlg->exec();
}
