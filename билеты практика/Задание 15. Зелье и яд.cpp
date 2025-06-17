#include <iostream>

class IUsable {
public:
	virtual void action(int count) = 0;
};

class Potion : public IUsable {
public:
	void action(int count) override {
		std::cout << "Вы вылечили себе " << count + rand() % 10 << " hp";
	}
};

class Poison : public IUsable {
public:
	void action(int count) override {
		std::cout << "Вы нанесли себе " << count + rand() % 10 << " урона";
	}
};

class Player {
	std::string name;
	int count_hp;

public:
	Player() {
		name = "Андрей";
		count_hp = 100;
	}
	void use(std::shared_ptr<IUsable> use, int count) {
		use->action(count);
	}
};

int main() {
	system("chcp 1251"); system("cls");

	std::shared_ptr<Potion> potion = std::make_shared<Potion>();
	std::shared_ptr<Poison> poizon = std::make_shared<Poison>();
	Player player;

	player.use(potion, 10);
	std::cout << std::endl;
	player.use(poizon, 15);
}