#ifndef TESTAPRIORITABLE_H
#define TESTAPRIORITABLE_H

#include <QObject>
#include <QtTest/QtTest>

#include <AutoTest.h>

namespace dm
{

class TestAprioriTable : public QObject
{
    Q_OBJECT

private slots:
    void test_normal (void);
};

DECLARE_TEST (TestAprioriTable)

}

#endif // TESTAPRIORITABLE_H
