#ifndef FDEDITDLG_H
#define FDEDITDLG_H

#include <QDialog>

namespace Ui {
class FdEditDlg;
}

class FdEditDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FdEditDlg(QWidget *parent = 0);
    ~FdEditDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::FdEditDlg *ui;
};

#endif // FDEDITDLG_H
