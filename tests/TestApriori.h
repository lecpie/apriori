#ifndef TESTAPRIORI_H
#define TESTAPRIORI_H

#include <QObject>
#include <QtTest/QtTest>

#include "AutoTest.h"

namespace dm
{

class TestApriori : public QObject
{
    Q_OBJECT

private slots:
    void test_normal (void);

};

DECLARE_TEST (TestApriori)

}

#endif // TESTAPRIORI_H
