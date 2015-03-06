#ifndef TESTDBSCANNER_H
#define TESTDBSCANNER_H

#include <QObject>
#include <QtTest/QtTest>

#include "DBScanner.h"
#include "AutoTest.h"

namespace dm
{

class TestDBScanner : public QObject
{
    Q_OBJECT

private slots:
    void test_sample (void);
};

DECLARE_TEST (TestDBScanner)

}


#endif // TESTDBSCANNER_H
