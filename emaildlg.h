#ifndef EMAILDLG_H
#define EMAILDLG_H

#include <QDialog>

namespace Ui {
class EmailDlg;
}

class EmailDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EmailDlg(QWidget *parent = 0);
    ~EmailDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::EmailDlg *ui;
};

#endif // EMAILDLG_H
