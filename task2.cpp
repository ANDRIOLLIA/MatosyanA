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
		name = "Земля";
	}

	void add(int density, int weight_10_24, int diameter, std::string name) {
		this->density = density;
		this->weight_10_24 = weight_10_24;
		this->diameter = diameter;
		this->name = name;
	}

	void info() {
		std::cout << "Планета: " << name << ", " << density << "-я планета от солнца, диаметр: "
			<< diameter << ", вес: " << weight_10_24;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Planet> planets;

	planets.at(0).add(5427, 0.33, 4873, "Меркурий");
	planets.at(1).add(5243, 4.87, 12104, "Венера");
	planets.at(2).add(5515, 5.97, 12756, "Земля");
	planets.at(3).add(3340, 0.073, 3475, "Луна");
	planets.at(4).add(3933, 0.642, 6794, "Марс");
	planets.at(5).add(1326, 1899, 142984, "Юпитер");
	planets.at(6).add(687, 568, 120536, "Сатурн");


	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).info();
	}
}