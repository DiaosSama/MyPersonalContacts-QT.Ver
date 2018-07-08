#include "emaildlg.h"
#include "ui_emaildlg.h"
#include "happydlg.h"
#include "ui_happydlg.h"
#include"myhead.h"

EmailDlg::EmailDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmailDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("发送邮件"));
    HappyDlg *ptr=(HappyDlg*)parentWidget();
    ui->namelb->setText(((ptr->name)+":"));
}

EmailDlg::~EmailDlg()
{
    delete ui;
}

void EmailDlg::on_yesBtn_clicked()
{
    QMessageBox::information(this,tr("提示"),tr("发送成功！"),QMessageBox::Yes);
    accept();
}
