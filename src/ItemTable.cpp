#include "ItemTable.h"

#include <algorithm>

using namespace std;

#define ITMTBLE dm::ItemTable

ITMTBLE::ItemTable (void) { }

unsigned ITMTBLE::add_item (const string & item)
{
    // If we found the item then we directly return the existing id
    iter_t it;
    if ((it = find(m_items.begin(), m_items.end(), item)) != m_items.end()) {
        return it - m_items.begin();
    }

    // Otherwise we add it to the end of the vector and return the last index
    m_items.push_back(item);

    return m_items.size() - 1;
}

string ITMTBLE::get_string (unsigned id) const
{
    return m_items.at(id);
}

unsigned ITMTBLE::get_size (void) const
{
    return m_items.size();
}

#undef ITMTBLE
