#include "TestDBScanner.h"

#include <string>
#include <iostream>
#include <fstream>

#include <ItemSet.h>
#include <ItemTable.h>

#define TSTDBSCN dm::TestDBScanner

using namespace std;
using namespace dm;

void TSTDBSCN::test_sample (void)
{
    ifstream in ("sample/example1.txt");

    QVERIFY (in.is_open());

    ItemTable table;

    DBScanner scanner(&table);

    scanner.set_input(in);

    for (ItemSet set; scanner.next(&set) && !set.empty(); set.clear())
    {

    }
}
