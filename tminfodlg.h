#ifndef TMINFODLG_H
#define TMINFODLG_H

#include <QDialog>

namespace Ui {
class TmInfoDlg;
}

class TmInfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit TmInfoDlg(QWidget *parent = 0);
    ~TmInfoDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::TmInfoDlg *ui;
};

#endif // TMINFODLG_H
