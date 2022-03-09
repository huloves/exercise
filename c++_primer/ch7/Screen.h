#ifndef __SCREEN_H
#define __SCREEN_H

#include <string>
#include <iostream>
#include <vector>
// #include "Window_mgr.h"

// class Window_mgr;

class Screen;

class Window_mgr {
public:
	// 窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
	// 向窗口添加一个Screen，返回它的编号
	ScreenIndex addScreen(const Screen&);
	// 按照编号将指定的Screen重置为空白
	inline void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen {
	// Window_mgr 的成员可以访问Screen类的私有部分
	// friend class Window_mgr;
	friend void Window_mgr::clear(ScreenIndex);
public:
	// typedef std::string::size_type pos;
	using pos = std::string::size_type;
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os) {
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const {
		do_display(os);
		return *this;
	}
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
	char get() const {              // 读取光标处的字符
		return contents[cursor];    // 隐式内联
	}
	inline char get(pos ht, pos wd) const;   // 显式内联
	Screen &move(pos r, pos c);     // 能在之后被设置为内联
	void some_member() const;
	pos size() const;
	Screen& clear(char = bkground);
private:
	void do_display(std::ostream &os) const { os << contents; }
	mutable size_t access_ctr;
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;   // 跟踪每个Screen的成员函数被调用了多少次
	static const char bkground;
};

Screen::pos Screen::size() const {
	return width * height;
}

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
	contents[r*width + col] = ch;
	return *this;
}

inline
Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}

void Screen::some_member() const {
	++access_ctr;   // 保存一个计数值，用于记录成员函数被调用的次数
}

Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s) {
	screens.push_back(s);
	return screens.size() - 1;
}

inline void Window_mgr::clear(ScreenIndex i) {
	// s是一个Screen的引用，指向我们想清空的那个屏幕
	Screen &s = screens[i];
	// 将那个选定的Screen重置为空白
	s.contents = std::string(s.height * s.width, ' ');
}

#endif
