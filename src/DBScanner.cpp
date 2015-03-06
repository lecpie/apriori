#include "DBScanner.h"

#include <string>
#include <sstream>

using namespace std;
using namespace dm;

#define DBSCN dm::DBScanner

DBSCN::DBScanner(ItemTable * table)
    : m_table (table) {}

void DBSCN::restart   (void)         { m_in->seekg(0); }
void DBSCN::set_input (istream & is) { m_in = &is;     }

istream & DBSCN::next  (ItemSet * items)
{
    string line;
    getline(*m_in, line);

    istringstream iss (line);

    for (std::string item; iss >> item; )
        items->insert(m_table->add_item(item));

    return *m_in;

} // next()
