#include <iostream>

class Heart {
public:
	Heart() {
		std::cout << "Heart is created\n";
	}
	~Heart() {
		std::cout << "Heart was destroyed\n";
	}
};

class Coin {
public:
	Coin() {
		std::cout << "Coin is created\n";
	}
	~Coin() {
		std::cout << "Coin was destroyed\n";
	}

};

class Human {
	Heart heart;
	std::shared_ptr<Coin> coin;
public:

	void takeCoin(std::shared_ptr<Coin>& coin) {
		this->coin = coin;
		coin.reset();
	}

	Human() {
		std::cout << "Human is created\n";
	}
	~Human() {
		std::cout << "Human was destroyed\n";
	}
};

int main() {
	system("chcp 1251"); system("cls");

	Human human;
	std::shared_ptr<Coin> coin = std::make_shared<Coin>();
	human.takeCoin(coin);
}