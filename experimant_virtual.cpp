#include <iostream>

class Old {
public:
	virtual void print() const {
		std::cout << "� ���\n";
	}
};

class Nouveau : public Old {
public:
	void print() const {
		std::cout << " � �� ���\n";
	}
};

int main() {
	system("chcp 1251");
	std::unique_ptr<Old> old_ptr = std::make_unique<Old>();
	old_ptr->print();
	std::unique_ptr<Old> old_ptr2 = std::make_unique<Nouveau>();
	old_ptr2->print();
	return 0;
}