#ifndef TMEDITDLG_H
#define TMEDITDLG_H

#include <QDialog>

namespace Ui {
class TmEditDlg;
}

class TmEditDlg : public QDialog
{
    Q_OBJECT

public:
    explicit TmEditDlg(QWidget *parent = 0);
    ~TmEditDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::TmEditDlg *ui;
};

#endif // TMEDITDLG_H
