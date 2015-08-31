#include "TestApriori.h"

#include <iostream>

#include "Apriori.h"

#define TSTAPR dm::TestApriori

using namespace std;
using namespace dm;

void TSTAPR::test_normal (void)
{
    ifstream in ("sample/example1.txt");

    QVERIFY2 (in.is_open(), "Sample file not open for test");

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

    QVERIFY (expected == candidates);
}
