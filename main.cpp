#include "mainwindow.h"
#include <QApplication>
#include"logdlg.h"
#include<QtWidgets>
#include"myhead.h"
#include<iostream>
#include<QDebug>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LogDlg dlg;
    if(dlg.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
   else
   return 0;
}
