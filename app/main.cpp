#include <iostream>
#include <fstream>
#include <vector>

#include <boost/timer/timer.hpp>

#include "Apriori.h"
#include "AprioriTable.h"

using namespace std;
using namespace dm;

namespace
{
    void usage (void)
    {
        cout << "apriori database minconf\n";

    } // usage()

} // namespace

int main(int argc, char * argv[])
{
    if (argc != 3) {
        cerr << "Wrong number of argument\n";

        usage();
        return 1;
    }

    char * input_path = argv[1];
    unsigned minconf;

    try {
        minconf = stoi(argv[2]);
    }
    catch (...) {
        cerr << "Error parsing minconf\n";
        usage();
        return 2;
    }

    ifstream is (input_path);

    if (!is.is_open()) {
        cerr << "Error oppening input file\n";
        usage();
        return 3;
    }

    boost::timer::auto_cpu_timer t;

    ItemTable items;
    Apriori apriori (is, minconf);

    vector <AprioriTable> candidates (apriori.generate_candidates(items));

    for (vector <AprioriTable>::size_type i (0); i < candidates.size(); ++i) {
        candidates[i].dump(items);
    }

    return 0;
}
