#-------------------------------------------------
#
# Project created by QtCreator 2018-06-03T23:28:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Contacts
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Person.cpp \
    Teammate.cpp \
    Classmate.cpp \
    Friend.cpp \
    logdlg.cpp \
    Function.cpp \
    Relative.cpp \
    cminfodlg.cpp \
    newdlg.cpp \
    tminfodlg.cpp \
    fdinfodlg.cpp \
    rtinfodlg.cpp \
    finddlg.cpp \
    temp.cpp \
    cmeditdlg.cpp \
    tmeditdlg.cpp \
    fdeditdlg.cpp \
    rteditdlg.cpp \
    countbirthdlg.cpp \
    happydlg.cpp \
    emaildlg.cpp

HEADERS += \
        mainwindow.h \
    Person.h \
    Classmate.h \
    Teammate.h \
    Relative.h \
    logdlg.h \
    Function.h \
    Friend.h \
    cminfodlg.h \
    newdlg.h \
    myhead.h \
    tminfodlg.h \
    fdinfodlg.h \
    rtinfodlg.h \
    finddlg.h \
    temp.h \
    cmeditdlg.h \
    tmeditdlg.h \
    fdeditdlg.h \
    rteditdlg.h \
    countbirthdlg.h \
    happydlg.h \
    emaildlg.h

FORMS += \
        mainwindow.ui \
    logdlg.ui \
    cminfodlg.ui \
    newdlg.ui \
    tminfodlg.ui \
    fdinfodlg.ui \
    rtinfodlg.ui \
    finddlg.ui \
    cmeditdlg.ui \
    tmeditdlg.ui \
    fdeditdlg.ui \
    rteditdlg.ui \
    countbirthdlg.ui \
    happydlg.ui \
    emaildlg.ui
