#ifndef __SALES_DATA_H
#define __SALES_DATA_H

#include <string>
#include <iostream>

struct Sales_data {
    // 关于Sales_data对象的操作
    // std::string isbn() const { return bookNo; }
    std::string isbn() const { return this->bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // 数据乘员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// Sales_data的非成员接口
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif
