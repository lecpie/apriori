#ifndef TESTITEMSET_H
#define TESTITEMSET_H

#include <QObject>
#include <QtTest/QtTest>

#include "AutoTest.h"

namespace dm
{

class TestItemSet : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(void);

    void test_normal (void);

    void test_duplicates  (void);
    void test_comparisons (void);
    void test_intersect   (void);
    void test_union       (void);
};

DECLARE_TEST (TestItemSet)

}

#endif // TESTITEMSET_H
