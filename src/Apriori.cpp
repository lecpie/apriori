#include "Apriori.h"

#include <vector>
#include <fstream>
#include <iterator>

#include "AprioriTable.h"
#include "DBScanner.h"
#include "ItemTable.h"
#include "ItemSet.h"

#define APR dm::Apriori

using namespace std;
using namespace dm;

APR::Apriori (std::istream & in, unsigned minsup)
    : m_in(&in), m_minsup (minsup) {}

void APR::set_minsup    (unsigned minsup)     { m_minsup = minsup;  }
void APR::set_input     (std::istream & is)   { m_in     = &is;     }


vector <AprioriTable> APR::generate_candidates (ItemTable & items)
{
    DBScanner scanner (&items);

    scanner.set_input(*m_in);

    vector <AprioriTable> l;
    vector <AprioriTable> c;

    // Initialize the first l with all items

    l.push_back(AprioriTable());

    for (ItemSet set; scanner.next(&set) && !set.empty(); set.clear()) {
        for (ItemSet::iterator it = set.begin(); it != set.end(); ++it) {
            ItemSet single;
            single.insert (*it);
            l.at(0).add_set (single);
        }
    }

    unsigned max_sz = 10;
    for (unsigned target_size = 2; l.back().size() != 0 && target_size < max_sz; ++target_size) {

        // Eliminate items without sufficient support into the c list
        c.push_back(l.back().prune (m_minsup));

        //initialize the content of the next l list as the items we bother checking if they are relevent
        l.push_back(AprioriTable());

        for (AprioriTable::iterator first = c.back().begin(); first != c.back().end(); ++first) {
            for (AprioriTable::iterator second = next(first, 1); second != c.back().end(); ++second) {
                ItemSet set (first->first.uni(second->first));

                if (set.size() == target_size)
                    l.back().insert(pair<ItemSet, unsigned> (set, 0));
            }
        }

        // Start reading the database again
        scanner.restart();

        for (ItemSet set; scanner.next(&set) && !set.empty(); set.clear()) {
            for (AprioriTable::iterator it = l.back().begin(); it != l.back().end(); ++it) {
                if (set.intersect(it->first) == it->first) {
                    l.back().add_set(it->first);
                }
            }
        }

    }

    return c;

} // generate_candidates()
