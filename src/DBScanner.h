#ifndef DBSCANNER_H
#define DBSCANNER_H

#include <istream>
#include <fstream>

#include "ItemTable.h"
#include "ItemSet.h"

namespace dm
{

class DBScanner
{
    std::istream * m_in;

    ItemTable * m_table;

public:
    DBScanner (ItemTable * table);

    void set_input (std::istream & is);

    std::istream & next  (ItemSet * items);
    void restart (void);

}; // classDBScanner

} // namespace

#endif // DBSCANNER_H
