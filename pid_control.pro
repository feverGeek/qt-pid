#-------------------------------------------------
#
# Project created by QtCreator 2019-03-09
#
#-------------------------------------------------

QT       += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = interaction-example
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
         ../../qcustomplot.cpp \
    pid/pid_incremental.cpp \
    pid/pid_position.cpp

HEADERS  += mainwindow.h \
         ../../qcustomplot.h \
    pid/pid_incremental.h \
    pid/pid_position.h

FORMS    += mainwindow.ui

