#include "AprioriTable.h"

#define APRTBLE dm::AprioriTable

using namespace std;
using namespace dm;

void APRTBLE::add_set  (ItemSet set)
{
    iterator it;

    if ((it = find(set)) == end()) {
        it = insert( std::pair <ItemSet, unsigned>(set, 0)).first;
    }
    ++it->second;

} // add_set()

AprioriTable APRTBLE::prune (unsigned minsup)
{
    AprioriTable res;

    for (AprioriTable::iterator it = begin(); it != end(); ++it) {
        if (it->second >= minsup) {
            res.insert(*it);
        }
    }

    return res;

} // prune()

std::ostream & APRTBLE::dump (std::ostream & os /* = std::cout */) const
{
    for (const_iterator it = begin(); it != end(); ++it) {
        os << it->first << " : " << it->second << endl;
    }

    return os;

} // dump()

std::ostream & APRTBLE::dump (const ItemTable & items,
                     std::ostream & os /* = std::cout */) const
{
    for (const_iterator it = begin(); it != end(); ++it) {
        it->first.dump (items, os) << " : " << it->second << endl;
    }

    return os;
}
