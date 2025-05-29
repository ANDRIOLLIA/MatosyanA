#include <iostream>
#include <vector>

class Planet {
	std::string name, color;
	double count_people_mlrd;
public:
	Planet(std::string name, std::string color, double count_people_mlrd) {
		this->name = name;
		this->color = color;
		this->count_people_mlrd = count_people_mlrd;
	}

	Planet() {
		name = "Земля";
		color = "голубой";
		count_people_mlrd = 8.2;
	}

	void createPanet() {
		std::cin >> name;
		std::cin >> color;
		std::cin >> count_people_mlrd;
	}

	void outputPlanet(Planet planet) {
		std::cout << "\nНазвание: " << planet.name << "\nЦвет:" << planet.color << "\nНаселение: " << planet.count_people_mlrd;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Planet> planets;
	planets.push_back(Planet("asd", "asd", 1234));
	planets.push_back(Planet("asdasd", "asdasd", 123));
	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).outputPlanet(planets.at(i));
	}
	
}