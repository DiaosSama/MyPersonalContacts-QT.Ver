#ifndef CMINFODLG_H
#define CMINFODLG_H

#include <QDialog>

namespace Ui {
class CmInfoDlg;
}

class CmInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CmInfoDlg(QWidget *parent = 0);
    ~CmInfoDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::CmInfoDlg *ui;
};

#endif // CMINFODLG_H
