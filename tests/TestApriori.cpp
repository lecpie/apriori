
#define BOOST_TEST_MODULE apriori
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "Apriori.h"

#include <iostream>

using namespace std;
using namespace dm;

namespace dm
{

BOOST_AUTO_TEST_SUITE( TestApriori )


BOOST_AUTO_TEST_CASE(test_normal)
{
    ifstream in ("sample/example1.txt");

    BOOST_CHECK (in.is_open());

    ItemTable items;

    Apriori apriori (in, 2);

    vector <AprioriTable> candidates (apriori.generate_candidates(items));

    ItemSet a(0), b(3), c(1), e(4),
            ac(a,c), bc(b,c), be(b,e), ce(c,e),
            bce (bc,e);

    AprioriTable frst; frst[a] = 2; frst[b] = 3; frst[c] = 3; frst[e] = 3;
    AprioriTable scnd; scnd[ac] = 2; scnd[bc] = 2; scnd[be] = 3; scnd[ce] = 2;
    AprioriTable thrd; thrd[bce] = 2;

    vector <AprioriTable> expected ({frst,scnd,thrd});

    BOOST_CHECK (expected == candidates);
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace dm
