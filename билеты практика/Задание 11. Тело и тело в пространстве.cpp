#include <iostream>

class Body {
	//������, ������, �������, �����
	int height, width, depth, weight;
	std::string material;
public:
	Body() {
		height = rand() % 10 + 1;
		width = rand() % 10 + 1;
		depth = rand() % 10 + 1;
		weight = rand() % 10 + 1;
		material = "������";
	}

	void info() {
		std::cout << "\n������: " << height << "\n������: " << width << "\n�������: " << depth
			<< "\n�����: " << weight << "\n��������: " << material;
	}
};

class AreaBody : public Body{
	int x, y, z;
public:
	AreaBody() : Body() {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		z = rand() % 10 + 1;
	}
};

int main() {

	system("chcp 1251"); system("cls");
	Body body;
	AreaBody area_body;

	body.info();
	std::cout << std::endl;
	area_body.info();
}