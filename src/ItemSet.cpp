#include "ItemSet.h"

#define ITMST dm::ItemSet

using namespace std;
using namespace dm;

ITMST::ItemSet (void) {}
ITMST::ItemSet (item_t a) { insert(a); }
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
    ItemSet res(b);

    for (iterator it = begin(); it != end(); ++it) {
        res.insert(*it);
    }

    return res;

} // uni()

ItemSet ITMST::operator - (const ItemSet & b) const
{
    const_iterator srch;
    ItemSet res(*this);

    for (iterator it = b.begin(); it != b.end(); ++it) {
        if ((srch = res.find(*it)) != res.end()) {
            res.erase(srch);
        }
    }

    return res;

} // operator - ()

ItemSet ITMST::operator - (const item_t  & b) const
{
    return *this - ItemSet(b);
}

ItemSet ITMST::operator + (const ItemSet & b) const
{
    return this->uni(b);

} // operator + ()

ostream & ITMST::dump (ostream & out) const
{
    const_iterator it = begin();

    // No item
    if (it == end()) return out;

    out << *it++;

    for ( ; it != end(); ++it)
        out << " " << *it;

    return out;

} // dump()

ostream & ITMST::dump (const ItemTable & items, std::ostream & out /* = std::cout */) const
{
    const_iterator it = begin();

    // No item
    if (it == end()) return out;

    out << items.get_string(*it++);

    for ( ; it != end(); ++it)
        out << " " << items.get_string(*it);

    return out;
}

