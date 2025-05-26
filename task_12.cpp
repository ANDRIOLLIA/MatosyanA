#include <iostream>
#include <vector>

class Dice {
	int number_of_faces;
public:
	Dice() {
		number_of_faces = 6;
	}

	~Dice() { std::cout << "\n€йца"; }

	int throwDice() {
		return rand() % number_of_faces + 1;
	}
};

class Player {
	std::vector <std::shared_ptr<Dice>> players_dices;
public:
	void takeDice(std::shared_ptr<Dice>& dice) {
		players_dices.push_back(dice);
		dice.reset();
		std::cout << "игрок вз€л кубик";
	}
	void putDice(std::shared_ptr<Dice>& dice) {
		dice = players_dices.back();
		players_dices.pop_back();
		std::cout << "игрок положил кубик";			
	}
	void throwAllDices() {
		if (players_dices.empty()) {
			std::cout << "у игрока нет кубиков";
		}
		else {
			for (int i = 0; i < players_dices.size(); i++) {
				if (players_dices.at(i) == nullptr) {
					continue;
				}
				int res = players_dices.at(i)->throwDice();
				std::cout << "на кубике " << i + 1 << " выпало число: " << res << std::endl;
			}
		}
	}
};

int main() {
	system("chcp 1251"); system("cls");
	srand(time(NULL));
	std::shared_ptr<Dice> dice1 = std::make_shared<Dice>();
	std::shared_ptr<Dice> dice2 = std::make_shared<Dice>();
	std::shared_ptr<Dice> dice3 = std::make_shared<Dice>();
	std::shared_ptr<Player> andrey = std::make_shared<Player>();
	
	andrey->takeDice(dice1);
	std::cout << std::endl;
	andrey->takeDice(dice2);
	std::cout << std::endl;
	andrey->takeDice(dice3);
	std::cout << std::endl;
	std::cout << std::endl;
	andrey->throwAllDices();
	std::cout << std::endl;
	andrey->putDice(dice1);
	std::cout << std::endl;	
	andrey->putDice(dice2);
	std::cout << std::endl;
	andrey->throwAllDices();
	andrey->putDice(dice3);
	std::cout << std::endl;
	std::cout << std::endl;
	andrey->takeDice(dice1);
	std::cout << std::endl;
	andrey->takeDice(dice2);
	std::cout << std::endl;
	andrey->takeDice(dice3);
	std::cout << std::endl;
}