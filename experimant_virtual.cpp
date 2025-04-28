#include <iostream>

class Test {
public:
	virtual int abstractTest() = 0;
};

class Old : public Test{
public:
	virtual void print() const {
		std::cout << "Я олд\n";
	}
	int abstractTest() override {
		std::cout << "Всё ок";
		return 0;
	}
};

class Nouveau : public Old {
public:
	void print() const {
		std::cout << " Я не олд\n";
	}
	int abstractTest() override {
		std::cout << "Всё ок";
		return 0;
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