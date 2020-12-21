#ifndef __SALES_DATA_H
#define __SALES_DATA_H

#include <string>

struct sales_data
{
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif
