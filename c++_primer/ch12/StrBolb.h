#ifndef __STRBOLB_H
#define __STRBOLB_H

#include <vector>
#include <string>
#include <memory>
#include <list>
#include <initializer_list>

using namespace std;

class StrBolb {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBolb();
	StrBolb(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加元素和删除元素
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	// 元素访问
	std::string& front();
	const string& front() const;
	std::string& back();
	const string& StrBolb::back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

StrBolb::StrBolb() : data(std::make_shared<std::vector<std::string>>()) { }

StrBolb::StrBolb(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBolb::check(size_t i, const string &msg) const {
	if(i >= data->size()) {
		throw out_of_range(msg);
	}
}

string& StrBolb::back() {
	check(0, "back on empty StrBolb");
	return data->front();
}

const string& StrBolb::back() const {
	check(0, "back on empty StrBolb");
	return data->back();
}

string& StrBolb::front() {
	check(0, "front on empty StrBolb");
	return data->back();
}

const string& StrBolb::front() const {
	check(0, "front on emtpy StrBolb");
	return data->front();
}

void StrBolb::pop_back() {
	check(0, "pop_back on empty StrBolb");
	return data->pop_back();
}

#endif
