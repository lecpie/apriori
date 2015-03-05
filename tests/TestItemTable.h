#ifndef TESTITEMTABLE_H
#define TESTITEMTABLE_H

#include <QObject>
#include <QtTest/QtTest>

#include "ItemTable.h"

namespace dm
{

class TestItemTable : public QObject
{
    Q_OBJECT

private:
    dm::ItemTable m_table;

private slots:
    void initTestCase(void);

    void test_normal     (void);
    void test_duplicate (void);
};

}

#endif // TESTITEMTABLE_H
