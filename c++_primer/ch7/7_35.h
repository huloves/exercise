#ifndef __7_35_H
#define __7_35_H

#include <string>

using namespace std;

typedef string Type;

Type initVal();
class Exercise {
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal();
private:
	int val;
};

Exercise::Type Exercise::setVal(Exercise::Type parm) {
	val = parm + initVal();
	return val;
}

#endif
