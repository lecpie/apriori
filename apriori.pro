TEMPLATE = subdirs
CONFIG+=ordered
CONFIG += c++11
CONFIG += debug

SUBDIRS = \
    src \
    app \
    tests

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
