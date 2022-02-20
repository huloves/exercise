#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string>

class Person {
friend std::istream &read(std::istream&, Person&);
friend std::ostream &print(std::ostream&, const Person&);

public:
	// 构造函数
	Person() = default;
	Person(const std::string &name, const std::string &address) : 
			name(name), address(address) { }

	std::string get_name() const { return name; }
	std::string get_address() const { return address; }
private:
	std::string name;
	std::string address;
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
