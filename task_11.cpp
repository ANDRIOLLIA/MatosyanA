#include <iostream>
#include <vector>

class Building {
	class Apartment {
		int square, count_rooms;
	public:
		Apartment() {
			square = rand() % 30 + 10;
			count_rooms = rand() % 4 + 1;
		}
		~Apartment() {
			std::cout << "\nAppartment was destroyed";
		}
		friend std::ostream& operator<< (std::ostream& out, const Apartment& apartment) {
			out << "\nПлощадь: " << apartment.square << "\nКоличество комнат: " << apartment.count_rooms << std::endl;
			return out;
		}
	};

	std::vector<std::unique_ptr <Apartment>> apartments;
public:
	Building() {}
	~Building() {
		std::cout << "\nBuilding was destroyed";
	}
	friend std::ostream& operator<< (std::ostream& out, const Building& building) {
		for (int i = 0; i < building.apartments.size(); i++) {
			out << *building.apartments.at(i);
		}
		return out;
	}

	void addApartment() {
		apartments.push_back(std::make_unique<Apartment>());
	}

	void destroyApartment() {
		apartments.erase(apartments.begin() + (apartments.size()-1));
	}

	void nullApartments(std::shared_ptr<Building> building) {
		building.reset();
	}
};

int main() {
	srand(time(NULL));
	system("chcp 1251"); system("cls");
	std::shared_ptr<Building> building = std::make_shared<Building>();
	
	for (int i = 0; i < rand() % 30 + 10; i++) {
		building->addApartment();
	}

	building->destroyApartment();
	building->nullApartments(building);

	std::cout << *building;
}