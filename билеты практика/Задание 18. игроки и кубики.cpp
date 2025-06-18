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
		cards.push_back(std::make_shared<Card>(9, "крести"));
		cards.push_back(std::make_shared<Card>(7, "черви"));
		cards.push_back(std::make_shared<Card>(2, "бубен"));
	}

	void getCard(std::shared_ptr<Card> card) {
		cards.push_back(card);
		card.reset();
		std::cout << "карта добавлена\n";
	}

	void putCard(std::shared_ptr<Card> card) {
		card = cards.back();
		cards.pop_back();
		std::cout << "карта убрана\n";
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector<std::shared_ptr<Card>> cards;
	std::shared_ptr<Card> card1 = std::make_shared<Card>(2, "бубен");
	std::shared_ptr<Card> card2 = std::make_shared<Card>(4, "черви");
	std::shared_ptr<Card> card3 = std::make_shared<Card>(7, "крести");
	std::shared_ptr<Card> card4 = std::make_shared<Card>(10, "пики");
	std::shared_ptr<Card> card5 = std::make_shared<Card>(5, "крести");
	std::shared_ptr<Card> card6 = std::make_shared<Card>(3, "черви");

	cards.push_back(card1);
	cards.push_back(card2);
	cards.push_back(card3);
	cards.push_back(card4);
	cards.push_back(card5);
	cards.push_back(card6);

	Player player1, player2;
	player1.getCard(card1);
	player1.getCard(card2);
	player1.getCard(card3);
	player1.getCard(card4);
	player1.getCard(card5);
	player1.getCard(card6);

	player1.putCard(card1);
	player1.putCard(card2);
	player1.putCard(card3);
	player1.putCard(card4);
	player1.putCard(card5);
	player1.putCard(card6);

	std::cout << std::endl << std::endl;

	player2.getCard(card1);
	player2.getCard(card2);
	player2.getCard(card3);
	player2.getCard(card4);
	player2.getCard(card5);
	player2.getCard(card6);

	player2.putCard(card1);
	player2.putCard(card2);
	player2.putCard(card3);
	player2.putCard(card4);
	player2.putCard(card5);
	player2.putCard(card6);
}