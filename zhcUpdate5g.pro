#-------------------------------------------------
#
# Project created by QtCreator 2016-01-27T13:35:50
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPort
TEMPLATE = app
RC_FILE = exe.rc


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    myfifo.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
