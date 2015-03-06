include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt
CONFIG += c++11


CONFIG += debug

TEMPLATE = lib

TARGET = apriori

SOURCES += ItemTable.cpp \
    ItemSet.cpp \
    AprioriTable.cpp \
    Apriori.cpp \
    DBScanner.cpp
HEADERS += ItemTable.h \
    ItemSet.h \
    AprioriTable.h \
    Apriori.h \
    DBScanner.h
