#-------------------------------------------------
#
# Project created by QtCreator 2018-09-09T22:57:23
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app

ICON = icon.icns

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    gamea.cpp \
    fishwidget.cpp \
    fish.cpp \
    utils.cpp \
    goldwidget.cpp \
    foodwidget.cpp \
    abstract_fish.cpp \
    global.cpp \
    si_object.cpp \
    objectwidget.cpp

HEADERS  += mainwindow.h \
    gamea.h \
    fishwidget.h \
    fish.h \
    utils.h \
    goldwidget.h \
    foodwidget.h \
    global.h \
    si_object.h \
    abstract_fish.h \
    si_geometry.hpp \
    objectwidget.h

FORMS    += mainwindow.ui \
    gamea.ui

RESOURCES += \
    resource.qrc
