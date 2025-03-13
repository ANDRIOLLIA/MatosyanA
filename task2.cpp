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

	Planet(int density, double weight_10_24, int diameter, std::string name) {
		this->density = density;
		this->weight_10_24 = weight_10_24;
		this->diameter = diameter;
		this->name = name;
	}

	void info() {
		std::cout << "Название: " << name << ", " << density << ", диаметр: "
			<< diameter << ", вес: " << weight_10_24;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Planet> planets;

	planets.push_back(Planet(5427, 0.33, 4873, "Меркурий"));
	planets.push_back(Planet(5243, 4.87, 12104, "Венера"));
	planets.push_back(Planet(5515, 5.97, 12756, "Земля"));
	planets.push_back(Planet(3340, 0.073, 3475, "Луна"));
	planets.push_back(Planet(3933, 0.642, 6794, "Марс"));
	planets.push_back(Planet(1326, 1899, 142984, "Юпитер"));
	planets.push_back(Planet(687, 568, 120536, "Сатурн"));

	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).info();
	}
}