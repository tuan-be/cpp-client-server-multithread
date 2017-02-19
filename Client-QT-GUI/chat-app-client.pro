#-------------------------------------------------
#
# Project created by QtCreator 2017-02-17T00:17:30
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chat-app-client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sockettest.cpp

HEADERS  += mainwindow.h \
    sockettest.h

FORMS    += mainwindow.ui
