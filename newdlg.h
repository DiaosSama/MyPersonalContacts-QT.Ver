#ifndef NEWDLG_H
#define NEWDLG_H

#include <QDialog>
#include"myhead.h"
namespace Ui {
class NewDlg;
}

class NewDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NewDlg(QWidget *parent = 0);
    ~NewDlg();
    CmInfoDlg *dlg;
    TmInfoDlg *tmdlg;
    FdInfoDlg *fddlg;
    RtInfoDlg *rtdlg;

private slots:
    void on_classmateBtn_clicked();

    void on_teammateBtn_clicked();

    void on_friendBtn_clicked();

    void on_relativeBtn_clicked();

private:
    Ui::NewDlg *ui;
};

#endif // NEWDLG_H
