#include <iostream>
#include <vector>

class Card {
	int value;
	std::string suit;
public:
	Card(int value, std::string suit) {
		this->value = value;
		this->suit = suit;
	}
};

class Player {
	std::vector<std::shared_ptr<Card>> cards;
public:
	Player() {
		cards.push_back(std::make_shared<Card>(5, "черви"));
		cards.push_back(std::make_shared<Card>(9, "бубен"));
		cards.push_back(std::make_shared<Card>(5, "крести"));
	}

	void getCard(std::shared_ptr<Card>& card) {
		cards.push_back(card);
		card.reset();
		std::cout << "карта добавлена";
	}

	void putCard(std::shared_)
};