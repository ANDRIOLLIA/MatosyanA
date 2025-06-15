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
		std::cout << "������� ��������: "; std::cin >> name;
		std::cout << "������� ����: "; std::cin >> color;
		std::cout << "������� ���������� ��������� � ����������: "; std::cin >> count_people_mlrd;
	}

	void info() {
		std::cout << "��������: " << name << "\n����: " << color << "\n���������: " << count_people_mlrd;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector<Planet> planets;
	planets.push_back(Planet("����", "�������", 0));
	planets.push_back(Planet("����", "�����", 0));
	planets.push_back(Planet("������", "����������", 0));
	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).info();
		std::cout << std::endl << std::endl;
	}
}