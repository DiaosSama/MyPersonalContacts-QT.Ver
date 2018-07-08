#ifndef FDINFODLG_H
#define FDINFODLG_H

#include <QDialog>

namespace Ui {
class FdInfoDlg;
}

class FdInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FdInfoDlg(QWidget *parent = 0);
    ~FdInfoDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::FdInfoDlg *ui;
};

#endif // FDINFODLG_H
