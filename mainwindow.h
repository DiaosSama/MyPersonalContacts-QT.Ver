#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"myhead.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    string n;
    NewDlg *dlg;
    FindDlg *fnddlg;
    CmEditDlg *cmdlg;
    TmEditDlg *tmdlg;
    FdEditDlg *fddlg;
    RtEditDlg *rtdlg;
    CountBirthDlg *cbdlg;
    HappyDlg *hpdlg;
    void Fresh();
    int cur_row;
    int flag;//判断点击的是哪个表格

private slots:
    void on_newBtn_clicked();

    void on_classmatetable_itemClicked(QTableWidgetItem *item);

    void on_deleteBtn_clicked();

    void on_teammatetable_itemClicked(QTableWidgetItem *item);

    void on_friendtable_itemClicked(QTableWidgetItem *item);

    void on_relativetable_itemClicked(QTableWidgetItem *item);

    void on_searchBtn_clicked();

    void on_editBtn_clicked();

    void on_countbirthBtn_clicked();

    void on_sortBtn_clicked();

    void on_happyBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
