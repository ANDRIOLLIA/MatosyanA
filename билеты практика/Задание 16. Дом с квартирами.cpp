#include <iostream>
#include <vector>

class Building {
	class Apartment {
	public:
		int square, count_rooms;
		Apartment() {
			square = rand() % 20 + 10;
			count_rooms = rand() % 5 + 1;
		}
		~Apartment() {
			std::cout << "\n\nКвартира удалена\n\n";
		}
		friend std::ostream& operator<<(std::ostream& out, const Apartment& apartment) {
			out << "\n\tПлощадь: " << apartment.square << "\n\tКоличество комнат: " << apartment.count_rooms;
			return out;
		}
	};
	std::vector<std::shared_ptr<Apartment>> apartments;
public:
	Building() {
		for (int i = 0; i < 10; i++) {
			apartments.push_back(std::make_shared<Apartment>());
		}
	}

	~Building() {
		std::cout << "Постройка удалена";
	}

	friend std::ostream& operator<<(std::ostream& out, const Building& building) {
		out << "Квартиры: ";
		for (int i = 0; i < building.apartments.size(); i++) {
			out << *building.apartments.at(i) << std::endl;
		}
		return out;
	}

	void addApartment() {
		apartments.push_back(std::make_shared<Apartment>());
	}

	void deleteApartment() {
		apartments.pop_back();
	}
};

int main() {
	system("chcp 1251"); system("cls");

	std::shared_ptr<Building> building = std::make_shared<Building>();
	std::cout << *building;
	building->addApartment();
	building->addApartment();
	building->addApartment();
	building->deleteApartment();
	building->deleteApartment();
	std::cout << std::endl << std::endl << *building;
}