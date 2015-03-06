#ifndef ITEMSET_H
#define ITEMSET_H

#include <set>
#include <iostream>

#include "ItemTable.h"

namespace dm
{

class ItemSet : public std::set <unsigned>
{
private:
    friend std::ostream & operator << (std::ostream & os, const ItemSet & set) { return set.dump(os); }

public:
    ItemSet (void);
    ItemSet (unsigned a);
    ItemSet (ItemSet a, ItemSet b);

    bool operator <  (const ItemSet & b) const;
    bool operator == (const ItemSet & b) const;

    ItemSet intersect (const ItemSet & b) const;
    ItemSet uni       (const ItemSet & b) const;

    std::ostream & dump (std::ostream & out = std::cout) const;
    std::ostream & dump (const ItemTable & items,
                         std::ostream & out = std::cout) const;

}; // class ItemSet

} // namespace dm

#endif // ITEMSET_H
