#ifndef COUNTBIRTHDLG_H
#define COUNTBIRTHDLG_H

#include <QDialog>

namespace Ui {
class CountBirthDlg;
}

class CountBirthDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CountBirthDlg(QWidget *parent = 0);
    ~CountBirthDlg();

private:
    Ui::CountBirthDlg *ui;
};

#endif // COUNTBIRTHDLG_H
