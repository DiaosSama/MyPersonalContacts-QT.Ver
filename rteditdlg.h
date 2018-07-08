#ifndef RTEDITDLG_H
#define RTEDITDLG_H

#include <QDialog>

namespace Ui {
class RtEditDlg;
}

class RtEditDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RtEditDlg(QWidget *parent = 0);
    ~RtEditDlg();

private slots:
    void on_yesBtn_clicked();

private:
    Ui::RtEditDlg *ui;
};

#endif // RTEDITDLG_H
