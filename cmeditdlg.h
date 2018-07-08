#ifndef CMEDITDLG_H
#define CMEDITDLG_H

#include <QDialog>

namespace Ui {
class CmEditDlg;
}

class CmEditDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CmEditDlg(QWidget *parent = 0);
    ~CmEditDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::CmEditDlg *ui;
};

#endif // CMEDITDLG_H
