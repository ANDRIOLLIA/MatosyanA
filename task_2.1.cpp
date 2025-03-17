#include <iostream>
#include <vector>

class Planet {
	std::string name;
	int diam, plotno;
	double massa;

public:
	Planet() { name = "noname"; diam = 0; plotno = 0; massa = 0; }

	Planet(std::string _name, int _diam, int _plotno, double _massa) {
		name = _name;
		diam = _diam;
		plotno = _plotno;
		massa = _massa;
	}

	void info() {
		std::cout << "\nНазвание планеты " << name << " \nдиаметр " << diam
			<< " \nплотность " << plotno << " \nмасса " << massa << std::endl;
	}
	std::string getName() const{
		return name;
	}
	Planet& setName(std::string _name) {
		name = _name;
		return *this;
	}
	int getDiam() const{
		return diam;
	}
	Planet& setDiam(int _diam) {
		diam = _diam;
		return *this;
	}
	int getPlonto() const{
		return plotno;
	}
	Planet& setPlotno(int _plotno) {
		plotno = _plotno;
		return *this;
	}
	double getMassa() const{
		return massa;
	}
	Planet& setMassa(double _massa) {
		massa = _massa;
		return *this;
	}
};

int main() {
	system("chcp 1251"), system("cls");
	std::vector<Planet>planets;

	planets.push_back(Planet("Меркурий", 4879, 5427, 0.330));
	planets.push_back(Planet("Венера", 12104, 5243, 4.87));
	planets.push_back(Planet("Земля", 12756, 5515, 5.97));
	planets.push_back(Planet("Марс", 6794, 3933, 0.642));
	planets.push_back(Planet("Юпитер", 142984, 1326, 1899));
	planets.push_back(Planet("Сатурн", 120536, 687, 568));
	planets.push_back(Planet("Уран", 51118, 1270, 86.8));
	planets.push_back(Planet("Нептун", 49528, 1638, 102));

	for (int i = 0; i < planets.size(); i++) {
		for (int j = 0; j < planets.size() - 1 - i; j++) {
			if (planets.at(j).getMassa() < planets.at(j + 1).getMassa()) {
				std::swap(planets.at(j), planets.at(j + 1));
			}
		}
	}

	for (int i = 0; i < planets.size(); i++) {
		planets.at(i).info();
	}
}