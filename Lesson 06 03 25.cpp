#include <iostream>
#include <vector>
class Marker {
	//Цвет, материал
	std::string color, material;
	int length, diam;
public:
	Marker() { 
		color = "черный"; 
		material = "пластик"; 
		length = 150; 
		diam = 3; 
	}
	
	Marker(std::string _color, std::string _material, int _length, int _diam) {
		color = _color;
		material = _material;
		length = _length;
		diam = _diam;
	}

	void info() {
		std::cout << "Маркер: " << color << ", материал " << material << ", длина " << length
			<< " мм., " << diam << " толщина линии\n";
	}
};

int main() {
	system("chcp 1251"); system("cls");

	std::vector<Marker>markers(3);
	markers.push_back(Marker("белый", "металл", 200, 1));

	for (int i = 0; i < markers.size(); i++) {
		markers.at(i).info();
	}
}