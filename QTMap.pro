#-------------------------------------------------
#
# Project created by QtCreator 2013-05-31T16:05:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTMap
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    myscene.cpp \
    wp.cpp

HEADERS  += mainwindow.h \
    view.h \
    myscene.h \
    wp.h
    
QT += widgets
qtHaveModule(printsupport): QT += printsupport
qtHaveModule(opengl): QT += opengl

RESOURCES += \
    images.qrc


