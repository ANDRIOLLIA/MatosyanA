#include <iostream>
#include <vector>

class Body {
	int id, amount = 0;
protected:
	int weight, a_coord, b_coord, jumping_ability;
public:
	Body() {
		id = amount;
		weight = NULL;
		a_coord = NULL;
		b_coord = NULL;
		jumping_ability = NULL;
		amount++;
	}

	virtual int dropIt(int force) = 0;
	void print() {
		std::cout << "\nID: " << id << "\n���: " << weight << "\n�: " << a_coord << "\n�: " << b_coord << "\n����������: " << jumping_ability;
	}
};

class Dice : public Body {
	int num;
public:
	Dice() {
		weight = 10;
		a_coord = 5;
		b_coord = 2;
		jumping_ability = 1;
	}

	int dropIt(int force) override {
		if (force >= 0)
			int num = rand() % 6 + 1;
		else if (force == 1488) {
			std::cout << "����� ������\n";
			std::cout << "������� �����: "; std::cin >> num;
		}
		return num;
	}
};

class Ball : public Body{
	int jump_height;
public:
	Ball(){
		weight = 7;
		a_coord = 4;
		b_coord = 8;
		jumping_ability = 10;
	}

	int dropIt(int force) {
		jump_height *= 7;
		return jump_height;
	}
};

int main() {
	system("chcp 1251");
	srand(time(NULL));

	std::unique_ptr<Dice> dice = std::make_unique<Dice>();
	dice->print();
	std::cout << dice->dropIt(4);

	std::unique_ptr<Ball> ball = std::make_unique<Ball>();
	ball->print();
	std::cout << ball->dropIt(4);

	return 0;
}