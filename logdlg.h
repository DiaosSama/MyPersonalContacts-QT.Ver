#ifndef LOGDLG_H
#define LOGDLG_H

#include <QDialog>

namespace Ui {
class LogDlg;
}

class LogDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LogDlg(QWidget *parent = 0);
    ~LogDlg();

private slots:
    void on_loginBtn_clicked();

private:
    Ui::LogDlg *ui;
};

#endif // LOGDLG_H
