#include <iostream>
#include <vector>

class Dice {
	int count_faces;
public:
	Dice() {
		count_faces = 6;
	}

	int throwDice() {
		return rand() % count_faces + 1;
	}
};

class Player {
	std::vector<std::shared_ptr<Dice>> dices;
public:
	Player() {
		dices.push_back(std::make_shared<Dice>());
		dices.push_back(std::make_shared<Dice>());
		dices.push_back(std::make_shared<Dice>());
	}

	void takeDice(std::shared_ptr<Dice> dice) {
		dices.push_back(dice);
		dice.reset();
		std::cout << "Кубик добавлен";
	}

	void throwAllDices() {
		for (int i = 0; i < dices.size(); i++) {
			std::cout << "\nВыпало число: " << dices.at(i)->throwDice();
		}
	}
};

int main() {
	system("chcp 1251"); system("cls");
	
	Player player;
	std::shared_ptr<Dice> dice = std::make_shared<Dice>();
	player.throwAllDices();
	std::cout << std::endl;
	player.takeDice(dice);
	std::cout << std::endl;
	player.throwAllDices();
}