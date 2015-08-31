#ifndef APRIORI_H
#define APRIORI_H

#include <iostream>
#include <vector>

#include "DBScanner.h"
#include "AprioriTable.h"

namespace dm
{

class Apriori
{
private:
    std::istream * m_in;

    unsigned m_minsup;
public:
    typedef std::vector <AprioriTable> table_list_t;

    Apriori (std::istream & in, unsigned minsup);

    void set_minsup    (unsigned minsup);
    void set_input     (std::istream & is);

    table_list_t generate_candidates (ItemTable & items);

}; // class Apriori

} // namespace dm

#endif // APRIORI_H
