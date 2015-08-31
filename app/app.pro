include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += ordered
TEMPLATE = app

TARGET = ../apriori

SOURCES += main.cpp

LIBS += -L../src -lapriori -lboost_timer -lboost_system
