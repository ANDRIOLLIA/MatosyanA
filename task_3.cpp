#include <iostream>

class Body {
	std::string name;
	int height, weight;
public:
	Body(std::string _name, int _height, int _weight) : name(_name), height(_height), weight(_weight){}

	void printInfo() {
		std::cout << "Имя: " << name << "\nРост: " << height << "\nВес: " << weight;
	}
};

class AreaBody : public Body {
	int x, y;
public:
	AreaBody(int _x, int _y): Body("yaico", 180, 75), x(_x), y(_y){}

	void printInfo() {
		Body::printInfo();
		std::cout << "\nX: " << x << "\nY: " << y;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	AreaBody andrey = AreaBody(88, 14);
	andrey.printInfo();
}