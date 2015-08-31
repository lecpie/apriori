// source : http://qtcreator.blogspot.se/2009/10/running-multiple-unit-tests.html

#include "TestItemSet.h"

#include "ItemSet.h"

#define TSTITMST dm::TestItemSet

using namespace std;
using namespace dm;


void TSTITMST::initTestCase(void)
{

}

void TSTITMST::test_normal (void)
{
    ItemSet items;

    items.insert(1);
    items.insert(3);

    QVERIFY (items.size() == 2);
}

void TSTITMST::test_duplicates  (void)
{

}

void TSTITMST::test_comparisons (void)
{

}

void TSTITMST::test_intersect   (void)
{
    ItemSet a, b;

    a.insert(1); a.insert(2);
    b.insert(2); b.insert(3);

    ItemSet c (a.intersect(b));
    ItemSet d (b.intersect(a));

    QVERIFY (c.size() == 1);
    QVERIFY (c == d);
}

void TSTITMST::test_union (void)
{
    ItemSet a, b;

    a.insert(1); a.insert(2);
    b.insert(2); b.insert(3);

    ItemSet c (a.uni(b));
    ItemSet d (b.uni(a));

    QVERIFY (c.size() == 3);
    QVERIFY (c == d);
}

void TSTITMST::test_minus (void)
{
    ItemSet a,b,e;

    a.insert(1); a.insert(2); a.insert(3);
    b.insert(1), b.insert(3); b.insert(4);

    e.insert(2);

    ItemSet c (a - b);

    QVERIFY (c.size() == 1);
    QVERIFY (c == e);

    QVERIFY ((a - 2) == (b - 4));
}

