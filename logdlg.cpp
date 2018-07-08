#include "logdlg.h"
#include "ui_logdlg.h"
#include<QtWidgets>

LogDlg::LogDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("个人通讯录管理系统"));
}

LogDlg::~LogDlg()
{
    delete ui;
}

void LogDlg::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text()==tr("admin")&&ui->pwdLineEdit->text()==tr("123456"))
    {
        accept();
    }
    else
    {
       QMessageBox::warning(this,tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
    }
}
