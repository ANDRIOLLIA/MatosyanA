#include <iostream>

class Body {
	int x, y, z;
	float jumpable = rand() % 1 * 0.1;
public:
	virtual int dropIt(int force) = 0;
	float getJumpable() const {
		return jumpable;
	}
	int getY() const {
		return y;
	}
};

class Dice : public Body{
	int num;
public:
	int dropIt(int force) override {
		int total = force * getJumpable() * getY();
		for (int i = 0; i < total; i++) {
			num = i;
			if (num > 6 || num == 0) num = 1;
		}
		return num;
	}
};

class Ball : public Body {

};

int main() {
	Dice dice;
	std::cout << dice.dropIt(10);
}