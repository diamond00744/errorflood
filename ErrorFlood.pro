#-------------------------------------------------
#
# Project created by QtCreator 2015-06-18T13:49:53
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = ErrorFlood
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    warningwindow.cpp \
    black.cpp \
    bsod.cpp \
    fullscreen.cpp

FORMS += \
    warningwindow.ui

HEADERS += \
    warningwindow.h \
    black.h \
    bsod.h \
    fullscreen.h

DISTFILES += \
    readme.txt \
    images/bsod.gif \
    images/icons/stop_by_emey87.png \
    images/icons/smile_by_everaldo_coelho.png
