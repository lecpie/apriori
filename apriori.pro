

TEMPLATE = subdirs

CONFIG += c++11
CONFIG += debug

SUBDIRS = \
    src \
    app \
    tests

src.subdir         = src

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
