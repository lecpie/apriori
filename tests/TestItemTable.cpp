#include "TestItemTable.h"

#include <string>

#define TSTITMTBLE dm::TestItemTable

using namespace std;
using namespace dm;

QTEST_MAIN (TestItemTable)

void TSTITMTBLE::initTestCase (void)
{
    string frst = "A", scnd = "C", thrd = "B", frth = "D";

    m_table.add_item ("A");
    m_table.add_item ("B");
    m_table.add_item ("D");
    m_table.add_item ("C");

    QVERIFY (m_table.get_size() == 4);
}

void TSTITMTBLE::test_normal (void)
{
    QVERIFY (m_table.get_string(0) == "A");
    QVERIFY (m_table.get_string(3) == "C");
    QVERIFY (m_table.get_string(1) == "B");
    QVERIFY (m_table.get_string(2) == "D");
}

void TSTITMTBLE::test_duplicate (void)
{
    // Try to add some items with strings already existing and compare the returned index
    QVERIFY (m_table.add_item ("A") == 0);
    QVERIFY (m_table.add_item ("B") == 1);
    QVERIFY (m_table.add_item ("D") == 2);
    QVERIFY (m_table.add_item ("C") == 3);

    // Despite our atempts to add, the table must stay the same
    QVERIFY (m_table.get_size() == 4);
}
