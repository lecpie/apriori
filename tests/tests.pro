include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11


QT += testlib

CONFIG += debug


TEMPLATE = app

LIBS += -L../src -lapriori

HEADERS += \
    AutoTest.h \
    TestItemTable.h \
    TestItemSet.h \
    TestDBScanner.h \
    TestApriori.h \
    TestAprioriTable.h

SOURCES += \
    main.cpp \
    TestItemTable.cpp \
    TestItemSet.cpp \
    TestDBScanner.cpp \
    TestApriori.cpp \
    TestAprioriTable.cpp
