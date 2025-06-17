#include <iostream>

class Body {
	int x, y, z;
	float jumpable;
public:
	virtual int dropIt(int force) = 0;
};

class Dice {
	int num;
};

class Ball {

};