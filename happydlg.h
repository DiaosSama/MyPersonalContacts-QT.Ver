#ifndef HAPPYDLG_H
#define HAPPYDLG_H

#include <QDialog>
#include"myhead.h"

namespace Ui {
class HappyDlg;
}

class HappyDlg : public QDialog
{
    Q_OBJECT

public:
    explicit HappyDlg(QWidget *parent = 0);
    ~HappyDlg();
    EmailDlg *edlg;
    QString name;

private slots:
    void on_happyBtn_clicked();

    void on_classmatetable_itemClicked(QTableWidgetItem *item);

private:
    Ui::HappyDlg *ui;
};

#endif // HAPPYDLG_H
