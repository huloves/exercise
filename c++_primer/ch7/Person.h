#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string>

struct Person {
	std::string name;
	std::string address;

	// 构造函数
	Person() = default;
	Person(const std::string &name, const std::string &address) : 
			name(name), address(address) { }

	std::string get_name() const { return name; }
	std::string get_address() const { return address; }
};

std::istream &read(std::istream &is, Person &item) {
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &item) {
    os << item.name << " " << item.address;
    return os;
}

#endif
