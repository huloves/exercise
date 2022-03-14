#ifndef __SALES_DATA_H
#define __SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:
    //构造函数
    // Sales_data() = default;   // 默认构造函数，在参数列表后面协商 = default来要求编译器生成构造函数
    explicit Sales_data(std::string s = "") : bookNo(s) { }
    // Sales_data(const std::string &s) : bookNo(s) { }   //构造函数初始值列表。花括号定义了空的函数体
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p * n) { }
    explicit Sales_data(std::istream &is);
    std::string isbn() const { return this->bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    // 关于Sales_data对象的操作
    // std::string isbn() const { return bookNo; }
    inline double avg_price() const
        { return units_sold ? revenue / units_sold : 0; }
    // 数据乘员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// Sales_data的非成员接口
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// double Sales_data::avg_price() const {
//     if(units_sold) {
//         return revenue / units_sold;
//     } else {
//         return 0;
//     }
// }

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

size_t hasher(const Sales_data &sd) {
    return hash<string>() (sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

#endif
