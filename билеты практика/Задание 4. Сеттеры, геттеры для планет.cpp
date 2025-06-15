#include <iostream>
#include <vector>

class Planet {
	std::string name, color;
	double count_people_mlrd;
public:
	Planet() {
		name = "Earth";
		color = "blue";
		count_people_mlrd = 7;
	}

	Planet& setName(std::string name) {
		this->name = name;
		return *this;
	}

	Planet& setColor(std::string color) {
		this->color = color;
		return *this;
	}

	Planet& setCountPeopleMlrd(double count_people_mlrd){
		this->count_people_mlrd = count_people_mlrd;
		return *this;
	}

	std::string getName() const {
		return name;
	}

	std::string getColor() const {
		return color;
	}

	double getCountPeopleMlrd() {
		return count_people_mlrd;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector<Planet> planets(3);
	int blades = 0;

	do {
		system("pause"); system("cls");
		std::cout << "1 - �������� ���\n2 - ��������������\n0 - �����\n>_"; std::cin >> blades;
		switch (blades) {
		case 1: {
			for (int i = 0; i < planets.size(); i++) {
				std::cout << "\nid: " << i << "\n��������: " << planets.at(i).getName() << "\n����: " << planets.at(i).getColor()
					<< "\n���-�� ���������(� ����������): " << planets.at(i).getCountPeopleMlrd() << std::endl;
			}
			break;
		}
		case 2: {
			int planet_to_redact;
			std::string name, color;
			double people;
			std::cout << "������� id �������: ";  std::cin >> planet_to_redact;
			std::cout << "������� ���: "; std::cin >> name; planets.at(planet_to_redact).setName(name);
			std::cout << "������� ����: "; std::cin >> color; planets.at(planet_to_redact).setColor(color);
			std::cout << "������� ���������� �����: "; std::cin >> people; planets.at(planet_to_redact).setCountPeopleMlrd(people);
			break;
		}
		}
	} while (blades != 0);
	return 0;
}