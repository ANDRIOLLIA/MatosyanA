#include <iostream>
#include <vector>

class Vehicle {
	int mileage;
	std::string brand;
public:
	Vehicle() {
		mileage = rand() % 100000 + 100000;
		brand = "BMW";
	}
	virtual void info() {
		std::cout << "\n\t������: " << mileage << "\n\t�����: " << brand;
	}
};

class Car : public Vehicle{
	bool is_active;
public:
	Car(bool is_active) : Vehicle() {
		this->is_active = is_active;
	}

	void info() override {
		std::cout << "\n������: ";
		Vehicle::info();
		std::cout << "\n\t�������: ";
		if (is_active)std::cout << "��";
		else std::cout << "���";
	}
};

class Bus : public Vehicle {
	int capacity;
public:
	Bus(int capacity) : Vehicle() {
		this->capacity = capacity;
	}

	void info() override {
		std::cout << "\n�������: ";
		Vehicle::info();
		std::cout << "\n\t���������������: " << capacity;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector<std::shared_ptr<Vehicle>> vehicles;
	vehicles.push_back(std::make_shared<Car>(true));
	vehicles.push_back(std::make_shared<Car>(false));
	vehicles.push_back(std::make_shared<Bus>(19));
	for (int i = 0; i < vehicles.size(); i++) {
		vehicles.at(i)->info();
		std::cout << std::endl;
	}
}