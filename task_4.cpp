#include <iostream>

class Body {
	static int amount;
	int id;
protected:
	int weight, x_coord, y_coord;
	double jump_ability;
public:
	Body() {
		id = ++amount;
		weight = rand() % 10;
		if (weight < 5)weight * 0.2;
		else weight * 0.1;
		x_coord = rand() % 10;
		y_coord = rand() % 10 + 1;
		jump_ability = rand() % 10 * 0.1;
		if (jump_ability == 0)jump_ability = 0.1;
	}
	virtual int dropIt(int force) = 0;
	void print() {
		std::cout << "\nid: " << id << "\nweight: " << weight << "\nX: " << x_coord << "\nY: " << y_coord << "\njump_ability: " << jump_ability;
	}
};

int Body::amount = 0;

class Dice : public Body {
	double num;
public:
	Dice() : Body() { num = 0; }
	int dropIt(int force) override {
		num = 1 + (5 * ((force * jump_ability) / (weight + y_coord)));
		if (num > 6)num = 6;
		x_coord = x_coord + rand() % 5;
		return num;
	}
};

class Ball : public Body {
	int jump_height;
public:
	Ball() : Body() { jump_height = 0; }
	int dropIt(int force) override {
		jump_height = y_coord + (jump_ability * (force / weight));
		x_coord = x_coord + rand() % 5 + 5;
		return jump_height;
	}
};

int main() {
	system("chcp 1251"); system("cls"); srand(time(NULL));
	Dice dice;
	Ball ball;

	dice.print();
	std::cout << "\n¬ам выпало число " << dice.dropIt(5) << std::endl;
	ball.print();
	std::cout << "\nћ€ч подпрыгнул на " << ball.dropIt(5) << " метров" << std::endl;
}