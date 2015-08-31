include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11


CONFIG += debug


TEMPLATE = app

LIBS += -L../src -lapriori -lboost_unit_test_framework

HEADERS += \

SOURCES += \
    TestApriori.cpp \
    TestDBScanner.cpp \
    TestItemSet.cpp \
    TestItemTable.cpp \
    TestAprioriTable.cpp
