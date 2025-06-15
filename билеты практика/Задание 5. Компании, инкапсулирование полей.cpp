#include <iostream>
#include <vector>

class Company {
	std::string name;
	int doxod, rasxod;
public:
	Company(std::string name, int doxod, int rasxod) {
		this->name = name;
		this->doxod = doxod;
		this->rasxod = rasxod;
	}

	std::string getName() const {
		return name;
	}

	int getDoxod() const {
		return doxod;
	}

	int getRasxod() const {
		return rasxod;
	}

	int getOborot() const {
		return doxod + rasxod;
	}

	int getChistayaPribil() const {
		return doxod - rasxod;
	}

	Company& setName(std::string name) {
		this->name = name;
		return *this;
	}

	Company& setDoxod(int doxod) {
		this->doxod = doxod;
		return *this;
	}

	Company& setRashod(int rasxod) {
		this->rasxod = rasxod;
		return *this;
	}
};

int main() {
	system("chcp 1251"); system("cls");
	int blades;

	std::vector <Company> companies;
	companies.push_back(Company("Яйца", 1001, 100));
	companies.push_back(Company("Яйца яйца", 1001, 100));
	companies.push_back(Company("Яйца яйца яйца", 1001, 100));

	do {
		system("pause"); system("cls");
		std::cout << "\n1.Показать все\n2.Редактировать\n0.Выход\n>_ "; std::cin >> blades;
		switch (blades) {
		case 1: {
			for (int i = 0; i < companies.size(); i++) {
				std::cout << "id: " << i << "\nНазвание: " << companies.at(i).getName() << "\nДоходы: " << companies.at(i).getDoxod() <<
					"\nРасходы: " << companies.at(i).getRasxod() << "\nОборот: " << companies.at(i).getOborot() << 
					"\nЧистая прибыль: " << companies.at(i).getChistayaPribil() << std::endl << std::endl;
			}
			break;
		}
		case 2: {
			int choice;
			std::cout << "1. Редактировать имя\n2. Редактировать доход\n3. Редактировать расход\n>_ "; std::cin >> choice;
			int id;
			std::cout << "Введите id компании: "; std::cin >> id;
			switch (choice) {
			case 1: {
				std::string name;
				std::cout << "Введите имя: "; std::cin >> name;
				companies.at(id).setName(name);
				break;
			}
			case 2: {
				int doxod;
				std::cout << "Введите доход: "; std::cin >> doxod;
				companies.at(id).setDoxod(doxod);
				break;
			}
			case 3: {
				int rasxod;
				std::cout << "Введите расход: "; std::cin >> rasxod;
				companies.at(id).setRashod(rasxod);
				break;
			}
			}
			break;
		}
		}

	} while (blades != 0);
}