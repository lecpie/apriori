#ifndef ITEMSET_H
#define ITEMSET_H

#include <set>
#include <iostream>

#include "ItemTable.h"

namespace dm
{

typedef unsigned item_t;

class ItemSet : public std::set <item_t>
{
private:
    friend std::ostream & operator << (std::ostream & os, const ItemSet & set) { return set.dump(os); }

public:
    ItemSet (void);
    ItemSet (item_t a);
    ItemSet (ItemSet a, ItemSet b);

    bool operator <  (const ItemSet & b) const;
    bool operator == (const ItemSet & b) const;

    ItemSet intersect (const ItemSet & b) const;
    ItemSet uni       (const ItemSet & b) const;

    ItemSet operator - (const ItemSet & b) const;
    ItemSet operator - (const item_t  & b) const;

    ItemSet operator + (const ItemSet & b) const;

    std::ostream & dump (std::ostream & out = std::cout) const;
    std::ostream & dump (const ItemTable & items,
                         std::ostream & out = std::cout) const;

}; // class ItemSet

} // namespace dm

#endif // ITEMSET_H
