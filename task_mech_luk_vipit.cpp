#include <iostream>

class Use {
public:
	virtual void use() = 0;	
};

class Sword : public Use{
	int weight, damage, random_status;
	double length;
public:
	Sword() {
		weight = 15;
		length = 1.65;
		damage = (rand() % 5 + 15) * weight * 0.3;
		random_status = rand() % 2;
	}

	void use() override {
		if (random_status == 0)
			std::cout << "SWORD-> Вы нанесли " << damage << " ед. урона";
		else if (random_status == 1) {
			std::cout << "SWORD-> У вас сломался меч";
			damage = 0;
		}
	}
};

class Bow : public Use {
	int weight, bowstring_tension, distance, damage, random_status;
	double length;
public:
	Bow() {
		weight = 7;
		length = 1.5;
		bowstring_tension = rand() % 5 + 1;
		distance = bowstring_tension * 10;
		damage = 3 * bowstring_tension;
		random_status = rand() % 3;
	}

	void use() override {
		if (random_status == 0)
			std::cout << "BOW-> Вы выстрелили на расстояние в " << distance << " метров и нанесли " << damage << " ед. урона";
		else if (random_status == 1) {
			std::cout << "BOW-> У вас порвалась тетева, лох";
			damage = 0;
		}
		else if (random_status == 2)
			std::cout << "BOW-> Стрела улетела в стратосферу, подожгла цыганское поселение и нанесла " << damage * 100 << " ед. урона по области";
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
		std::cout << "POTION-> Вы выпили " << volume << " мл. зелья и ";
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
	srand(time(NULL));
	system("chcp 1251"); system("cls");
	Player andrey;
	std::shared_ptr<Sword> sword = std::make_shared<Sword>();
	std::shared_ptr<Bow> bow = std::make_shared<Bow>();
	std::shared_ptr<Potion> potion = std::make_shared<Potion>();
	andrey.use(sword); std::cout << "\n\n";
	andrey.use(bow); std::cout << "\n\n";
	andrey.use(potion);std::cout << "\n";
}