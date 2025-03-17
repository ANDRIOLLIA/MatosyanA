#include <iostream>
#include <vector>
class Marker {
	//Цвет, материал
	std::string color, material;
	int length, diam;
public:
	explicit Marker() { 
		color = "черный"; 
		material = "пластик"; 
		length = 150; 
		diam = 3; 
	}

	explicit Marker(std::string _color, std::string _material, int _length, int _diam) {
		color = _color;
		material = _material;
		length = _length;
		diam = _diam;
	}

	Marker(bool bl) {

	}

	void info() const {
		std::cout << "Маркер: " << color << ", материал " << material << ", длина " << length
			<< " мм., " << diam << " толщина линии\n";
	}
	void setColor(std::string _color) {
		color = _color;
	}
	std::string getColor() const{
		return color;
	}
	Marker& setLength(int _lenth) {
		if (_lenth > 0) length = _lenth;
		return *this;
	}

	inline void hello() {
		std::cout << "hello";
	}
};

void printMarkers(const std::vector<Marker>& markers) {
	for (int i = 0; i < markers.size(); i++) {
		markers.at(i).info();
		markers.at(i).getColor();
	}
}

int main() {
	system("chcp 1251"); system("cls");

	std::vector<Marker>markers(3);
	markers.push_back(Marker("белый", "металл", 200, 1));
	
	Marker mk(100);
	Marker mk = 100;
	Marker mk;
	mk = 100;

	mk = Marker(100);

	markers.at(0).hello();
}