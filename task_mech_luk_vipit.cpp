#include <iostream>

class Use {
public:
	virtual void use() = 0;	
};

class Sword : public Use{
	int weight, damage;
	double length;
public:
	Sword() {
		weight = 15;
		length = 1.65;
		damage = rand() % 5 + 15;
	}

	void use() override {
		std::cout << "\nsword-> Вы нанесли " << damage << " урона по мишени";
	}
};

class Bow : public Use {
	int weight, bowstring_tension, distance, damage;
	double length;
public:
	Bow() {
		weight = 7;
		length = 1.5;
		bowstring_tension = rand() % 5 + 1;
		distance = bowstring_tension * 10;
		damage = 3 * bowstring_tension;
	}

	void use() override {
		std::cout << "\nbow-> Вы выстрелили на расстояние в " << distance << " метров и нанесли " << damage << " ед. урона";
	}
};

class Potion : public Use {
	int volume;
	bool is_heal;
public:
	Potion() {
		volume = 100;
		is_heal = rand() % 2;
	}
	void use() override {
		std::cout << "\npotion-> Вы выпили " << volume << " мл. зелья и ";
		if (is_heal)std::cout << "исцелили 10 hp (не ноутбуков)";
		else std::cout << "отравились";
	}
};

class Player{
	double height, weight, strength;

public:
	Player() {
		height = 1.85;
		weight = 79;
		strength = 100;
	}

	void use(std::shared_ptr<Use> use) {
		use->use();
	}
};

int main() {
	system("chcp 1251"); system("cls");
	Player andrey;
	std::shared_ptr<Sword> sword = std::make_shared<Sword>();
	std::shared_ptr<Bow> bow = std::make_shared<Bow>();
	std::shared_ptr<Potion> potion = std::make_shared<Potion>();
	srand(time(NULL));
	andrey.use(sword);
	andrey.use(bow);
	andrey.use(potion);
}