
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <string>
#include <iostream>
#include <fstream>

#include <ItemSet.h>
#include <ItemTable.h>
#include <DBScanner.h>

using namespace std;

namespace dm
{

BOOST_AUTO_TEST_SUITE(TestDBScanner)

BOOST_AUTO_TEST_CASE (test_sample)
{
    ifstream in ("sample/example1.txt");

    BOOST_REQUIRE (in.is_open());

    ItemTable table;

    DBScanner scanner(&table);

    scanner.set_input(in);

    for (ItemSet set; scanner.next(&set) && !set.empty(); set.clear())
    {

    }
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace dm
