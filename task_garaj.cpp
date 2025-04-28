#include <iostream>
#include <vector>

class Vehicle {
	std::string brand;
	int mileage;
public:
	Vehicle(std::string _brand, int _mileage) :brand(_brand), mileage(_mileage) {}
	virtual void printInfo() {
		std::cout << "Марка: "  << brand << ", пробег: " << mileage;
	}
};

class Car : public Vehicle {
	bool is_active;
public:
	Car(bool _is_active) :Vehicle("matiz", 1000000), is_active(_is_active){}
	void printInfo() override {
		Vehicle::printInfo();
		std::cout << "\nМашина ";
		if (is_active)std::cout << "работает";
		if (!is_active)std::cout << "не работает";
	}
};

class Bus : public Vehicle {
	int capacity;
public:
	Bus(int _capacity) : Vehicle("Hyundai", 139197), capacity(_capacity){}
	void printInfo() override {
		Vehicle::printInfo();
		std::cout << "\nВместимость: " << capacity << " мест";
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector<std::shared_ptr<Vehicle>> garaj;
	garaj.push_back(std::make_shared<Bus>(13));
	garaj.push_back(std::make_shared<Car>(1));
	for (int i = 0; i < garaj.size(); i++) {
		garaj.at(i)->printInfo();
		std::cout << "\n\n";
	}
}