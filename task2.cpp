#include<iostream>
#include <vector>
class Planet {
	int position_away_sun, weight_10_24, diameter;
	std::string name;
public:
	Planet() {
		position_away_sun = 3;
		weight_10_24 = 5, 97;
		diameter = 12756;
		name = "�����";
	}
	void add_parameters() {
		std::cout << "������� ������� �� ������: "; std::cin >> position_away_sun;
		std::cout << "������� ��� � ������ (10^24): "; std::cin >> weight_10_24;
		std::cout << "������� �������: "; std::cin >> diameter;
		std::cout << "������� ��������: "; std::cin >> name;
		std::cout << std::endl;
	}
	void info() {
		std::cout << "�������: " << name << ", " << position_away_sun << "-� ������� �� ������, �������: "
			<< diameter << ", ���: " << weight_10_24;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Planet> planets(7);

	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).add_parameters();
	}
	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).info();
	}
}