#include "ItemSet.h"

#define ITMST dm::ItemSet

using namespace std;
using namespace dm;

ITMST::ItemSet (void) {}
ITMST::ItemSet (unsigned a) { insert(a); }
ITMST::ItemSet (ItemSet a, ItemSet b) : ItemSet(a.uni(b)) { }

bool ITMST::operator < (const ItemSet & b) const
{
    // Rules :
    // A set with lower item number is inferior
    // Compare each item ids in the sets and return the result of the comparison of the firsts not equals

    if (size() != b.size())
        return size() < b.size();

    for (iterator it_a = begin(), it_b = b.begin();
         it_a != end() && it_b != b.end(); ++it_a, ++it_b)
    {
        if (*it_a != *it_b)
            return *it_a < *it_b;
    }

    // Here they are equals so one is not inferior

    return false;

} // operator < ()

bool ITMST::operator == (const ItemSet & b) const
{
    if (size() != b.size())
        return false;

    for (iterator it_a = begin(), it_b = b.begin();
         it_a != end() && it_b != b.end(); ++it_a, ++it_b)
    {
        if (*it_a != *it_b)
            return false;
    }

    // Here they are equals so one is not inferior

    return true;

} // operator == ()

ItemSet ITMST::intersect (const ItemSet & b) const
{
    ItemSet res;

    for (iterator it = begin(); it != end(); ++it) {
        if (b.find(*it) != b.end())
            res.insert(*it);
    }

    return res;

} // intersect()

ItemSet ITMST::uni (const ItemSet & b) const
{
    ItemSet res (b);

    for (iterator it = begin(); it != end(); ++it) {
        res.insert(*it);
    }

    return res;

} // uni()

ostream & ITMST::dump (ostream & out) const
{
    out << "{";

    for (iterator it = begin(); it != end(); ++it)
        out << " " << *it;

    out << " }";

    return out;

} // dump()

ostream & ITMST::dump (const ItemTable & items, std::ostream & out /* = std::cout */) const
{
    out << "{";

    for (iterator it = begin(); it != end(); ++it)
        out << " " << items.get_string(*it);

    out << " }";

    return out;
}

