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

    AprioriTable * cur_l;
    AprioriTable * cur_c;

    // First generate first l list with all items

    l.push_back(AprioriTable());
    cur_l = &l.back();

    // For each input itemset
    for (ItemSet set; scanner.next(&set) && !set.empty(); set.clear()) {

        // For each item in this itemset
        for (ItemSet::iterator it = set.begin(); it != set.end(); ++it) {

            // Add it to the l list
            cur_l->add_set (*it);
        }
    }

    // Try to generate frequent itemsets in c list until l list is empty
    // Or until some limit item set size

    unsigned max_sz = 10;
    for (unsigned target_size = 2; cur_l->size() != 0 && target_size < max_sz; ++target_size) {

        // Eliminate items without sufficient support into the c list
        c.push_back(cur_l->prune (m_minsup));

        // c list complete, generate next l list now to be pruned as next c list if not empty

        //initialize the content of the next l list as the items we bother checking if they are relevent
        l.push_back(AprioriTable());

        cur_l  = &l.back();
        cur_c  = &c.back();

        // For each generated candiates as "first"
        for (AprioriTable::iterator first = cur_c->begin(); first != cur_c->end(); ++first) {

            // For each generated candiate as "second", forming an unique pair with "first"
            for (AprioriTable::iterator second = next(first, 1); second != cur_c->end(); ++second) {

                // make an union set with this candidate pair
                ItemSet set (first->first.uni(second->first));

                // Try another pair if the resulting set is not of the expected size
                if (set.size() != target_size) continue;

                // See if this set validate the apriori property :
                // All subsets have to be candidates for this one to possibly be one.
                // Only check subsets of size -1 as others are inductivly candididates
                bool apriory_property = true;

                // For each item in this itemset
                for (ItemSet::const_iterator itm = set.begin(); itm != set.end(); ++itm) {

                    // Make an subset removing this item from the current itemset
                    ItemSet subset = set - *itm;

                    // This subset must be in the candidate list to validate the apriory property on the current itemset
                    if (cur_c->find(subset) == cur_c->end()) {
                        apriory_property = false;
                        break;
                    }
                }

                // Accept this itemset if it validates the apriory property
                if (apriory_property) {
                    cur_l->insert(pair<ItemSet, unsigned> (set, 0));
                }
            }
        }

        // Start reading the database again
        scanner.restart();

        for (ItemSet set; scanner.next(&set) && !set.empty(); set.clear()) {
            for (AprioriTable::iterator it = cur_l->begin(); it != cur_l->end(); ++it) {
                if (set.intersect(it->first) == it->first) {
                    cur_l->add_set(it->first);
                }
            }
        }

    }

    return c;

} // generate_candidates()
