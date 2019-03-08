#-------------------------------------------------
#
# Project created by QtCreator 2019-01-30T12:59:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = application
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
    importer.cpp \
    reader.cpp \
    individualsheet.cpp \
    transcriptmaker.cpp \
    student.cpp \
    grades.cpp \
    studentmanager.cpp \
    exporter.cpp \
    datapersist.cpp

HEADERS += \
        mainwindow.h \
    importer.h \
    reader.h \
    individualsheet.h \
    transcriptmaker.h \
    student.h \
    grades.h \
    studentmanager.h \
    exporter.h \
    datapersist.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    sample.qrc

# Adding QtXlsx source code to the project
include(3rdparty/QtXlsxWriter/src/xlsx/qtxlsx.pri)
