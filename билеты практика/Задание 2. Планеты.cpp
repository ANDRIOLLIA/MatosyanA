#include <iostream>
#include <vector>

class Planet {
	std::string name, color;
	int count_people_mlrd;
public:
	Planet() {
		name = "Earth";
		color = "blue";
		count_people_mlrd = 75;
	}

	Planet(std::string name, std::string color, int count_people_mlrd) {
		this->name = name;
		this->color = color;
		this->count_people_mlrd = count_people_mlrd;
	}

	void redact() {
		std::cout << "Введите название: "; std::cin >> name;
		std::cout << "Введите цвет: "; std::cin >> color;
		std::cout << "Введите количество населения в миллиардах: "; std::cin >> count_people_mlrd;
	}

	void info() {
		std::cout << "Название: " << name << "\nЦвет: " << color << "\nНаселение: " << count_people_mlrd;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector<Planet> planets;
	planets.push_back(Planet("Марс", "красный", 0));
	planets.push_back(Planet("Уран", "синий", 0));
	planets.push_back(Planet("Плутон", "коричневый", 0));
	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).info();
		std::cout << std::endl << std::endl;
	}
}