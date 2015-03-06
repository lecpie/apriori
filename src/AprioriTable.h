#ifndef APRIORITABLE_H
#define APRIORITABLE_H

#include <map>
#include <iostream>

#include "ItemSet.h"
#include "ItemTable.h"

namespace dm
{

class AprioriTable : public std::map <ItemSet, unsigned>
{
public:
    void add_set (ItemSet set);

    AprioriTable prune (unsigned minsup);

    std::ostream & dump (std::ostream & os = std::cout) const;
    std::ostream & dump (const ItemTable & items,
                         std::ostream & os = std::cout) const;

}; // class AprioriTable

} // namespace dm

#endif // APRIORITABLE_H
