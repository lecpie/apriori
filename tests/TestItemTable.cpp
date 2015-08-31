#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "ItemTable.h"

#include <string>


using namespace std;

namespace dm
{


struct TestItemTableFixture {
    TestItemTableFixture()
        : m_table()
    {
        string frst = "A", scnd = "C", thrd = "B", frth = "D";

        m_table.add_item ("A");
        m_table.add_item ("B");
        m_table.add_item ("D");
        m_table.add_item ("C");
    }

    ~TestItemTableFixture()
    {

    }

    ItemTable m_table;
};

BOOST_FIXTURE_TEST_SUITE (TestItemTable, TestItemTableFixture)

BOOST_AUTO_TEST_CASE (test_normal)
{
    BOOST_REQUIRE_MESSAGE (m_table.get_size() == 4, "wrong item table size on init");

    BOOST_CHECK_EQUAL (m_table.get_string(0), "A");
    BOOST_CHECK_EQUAL (m_table.get_string(3), "C");
    BOOST_CHECK_EQUAL (m_table.get_string(1), "B");
    BOOST_CHECK_EQUAL (m_table.get_string(2), "D");
}

BOOST_AUTO_TEST_CASE (test_duplicate)
{
    // Try to add some items with strings already existing and compare the returned index
    BOOST_CHECK_EQUAL (m_table.add_item ("A"), 0);
    BOOST_CHECK_EQUAL (m_table.add_item ("B"), 1);
    BOOST_CHECK_EQUAL (m_table.add_item ("D"), 2);
    BOOST_CHECK_EQUAL (m_table.add_item ("C"), 3);

    // Despite our atempts to add, the table must stay the same
    BOOST_CHECK_EQUAL (m_table.get_size(), 4);
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace dm
