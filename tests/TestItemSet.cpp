#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "ItemSet.h"

using namespace std;

namespace dm
{

BOOST_AUTO_TEST_SUITE( TestItemSet )

BOOST_AUTO_TEST_CASE (test_normal)
{
    ItemSet items;

    items.insert(1);
    items.insert(3);

    BOOST_CHECK (items.size() == 2);
}

BOOST_AUTO_TEST_CASE (test_duplicates)
{

}

BOOST_AUTO_TEST_CASE (test_comparisons)
{

}

BOOST_AUTO_TEST_CASE (test_intersect)
{
    ItemSet a, b;

    a.insert(1); a.insert(2);
    b.insert(2); b.insert(3);

    ItemSet c (a.intersect(b));
    ItemSet d (b.intersect(a));

    BOOST_CHECK (c.size() == 1);
    BOOST_CHECK (c == d);
}

BOOST_AUTO_TEST_CASE (test_union)
{
    ItemSet a, b;

    a.insert(1); a.insert(2);
    b.insert(2); b.insert(3);

    ItemSet c (a.uni(b));
    ItemSet d (b.uni(a));

    BOOST_CHECK (c.size() == 3);
    BOOST_CHECK (c == d);
}

BOOST_AUTO_TEST_CASE (test_minus)
{
    ItemSet a,b,e;

    a.insert(1); a.insert(2); a.insert(3);
    b.insert(1), b.insert(3); b.insert(4);

    e.insert(2);

    ItemSet c (a - b);

    BOOST_CHECK (c.size() == 1);
    BOOST_CHECK (c == e);

    BOOST_CHECK ((a - 2) == (b - 4));
}

BOOST_AUTO_TEST_SUITE_END()

}
