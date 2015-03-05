include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle

QT += testlib

TEMPLATE = app

LIBS += -L../src -lapriori

HEADERS += \
    TestItemTable.h

SOURCES += \
    TestItemTable.cpp
