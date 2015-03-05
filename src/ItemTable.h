#ifndef ITEMTABLE_H
#define ITEMTABLE_H

#include <vector>
#include <string>

namespace dm
{

class ItemTable
{
private:
    typedef std::vector <std::string> container_t;
    typedef container_t::iterator     iter_t;

    container_t m_items;

public:
    ItemTable (void);

    // Add an item to the list if it does not exists
    // and return the new atributed id
    unsigned add_item (const std::string & item);

    // get a copy of the string associated to a given id
    std::string get_string (unsigned id) const;

    // Get the number if item in the table
    unsigned get_size (void) const;
};

#endif // ITEMTABLE_H

}
