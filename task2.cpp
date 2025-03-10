#include<iostream>
#include <vector>
class Planet {
	int density, weight_10_24, diameter;
	std::string name;
public:
	Planet() {
		density = 5427;
		weight_10_24 = 5.97;
		diameter = 12756;
		name = "�����";
	}

	void add(int density, int weight_10_24, int diameter, std::string name) {
		this->density = density;
		this->weight_10_24 = weight_10_24;
		this->diameter = diameter;
		this->name = name;
	}

	void info() {
		std::cout << "�������: " << name << ", " << density << "-� ������� �� ������, �������: "
			<< diameter << ", ���: " << weight_10_24;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Planet> planets;

	planets.at(0).add(5427, 0.33, 4873, "��������");
	planets.at(1).add(3, 5.97, 12756, "������");
	planets.at(2).add(3, 5.97, 12756, "�����");
	planets.at(3).add(3, 5.97, 12756, "�����");
	planets.at(4).add(3, 5.97, 12756, "�����");
	planets.at(5).add(3, 5.97, 12756, "�����");
	planets.at(6).add(3, 5.97, 12756, "�����");


	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).info();
	}
}