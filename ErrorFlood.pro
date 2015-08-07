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

# VERSION = $$system(svn info -r HEAD . | grep 'Changed\ Rev' | cut -b 19-)
# !isEmpty(VERSION){
# VERSION = 0.$${VERSION}
# VERSION = 1.0
# }
# VERSTR = '\\"$${VERSION}\\"' # place quotes around the version string.


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
    fullscreen.h \
    version.h

DISTFILES += \
    readme.txt \
    images/bsod.gif \
    images/icons/stop_by_emey87.png \
    images/icons/smile_by_everaldo_coelho.png \
    warning_by_turbomilk.ico \
    resources.rc

RC_FILE = resources.rc


DEFINES += VER=\"$${VER_PRODUCTVERSION_STR}\" # create a VER macro containing the version string
