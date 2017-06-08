#-------------------------------------------------
#
# Project created by QtCreator 2017-05-29T00:11:27
#
#-------------------------------------------------
QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = CarRent2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    login.cpp \
    visit.cpp \
    register.cpp \
    userlogin.cpp \
    workerlogin.cpp \
    syslogin.cpp \
    revisebasicinfo.cpp \
    deposit.cpp \
    revisepass.cpp \
    addcarinfo.cpp \
    addworkerinfo.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

FORMS += \
    login.ui \
    visit.ui \
    register.ui \
    userlogin.ui \
    workerlogin.ui \
    syslogin.ui \
    revisebasicinfo.ui \
    deposit.ui \
    revisepass.ui \
    addcarinfo.ui \
    addworkerinfo.ui

HEADERS += \
    login.h \
    main.h \
    visit.h \
    register.h \
    userlogin.h \
    workerlogin.h \
    syslogin.h \
    revisebasicinfo.h \
    deposit.h \
    revisepass.h \
    addcarinfo.h \
    addworkerinfo.h
