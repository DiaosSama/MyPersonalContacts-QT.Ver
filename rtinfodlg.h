#ifndef RTINFODLG_H
#define RTINFODLG_H

#include <QDialog>

namespace Ui {
class RtInfoDlg;
}

class RtInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RtInfoDlg(QWidget *parent = 0);
    ~RtInfoDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::RtInfoDlg *ui;
};

#endif // RTINFODLG_H
