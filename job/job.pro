QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = job
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    page.cpp \
    pageother.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    pageother.h \
    mainwindow.h\
    page.h
