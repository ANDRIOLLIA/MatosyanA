#include <iostream>
#include <vector>

class Company {
	std::string name;
	int doxod, rasxod, oborot, chistaya_pribil;
	bool is_gos_company;
public:
	Company() {
		name = "pipiski";
		doxod = 0;
		rasxod = 0;
		oborot = 0;
		chistaya_pribil = 0;
		is_gos_company = false;
	}

	Company& setCompany() {
		std::cout << "Введите название компании: "; std::cin >> name;
		std::cout << "Введите доходы: "; std::cin >> doxod;
		std::cout << "Введите расходы: "; std::cin >> rasxod;
		std::cout << "Введите государственная компания или нет(1 или 0): "; std::cin >> is_gos_company;
		return *this;
	}

	std::string getName() {return name;}
	
	int getDoxod() {
		if (!is_gos_company && oborot < 5000000)return 0;
		else if (is_gos_company)return 0;
		return doxod;
	}
	
	int getRasxod() {
		if (!is_gos_company && oborot < 5000000)return 0;
		else if (is_gos_company)return 0;
		return rasxod;
	}

	int getOborot(){
		if (!is_gos_company && oborot < 5000000)return 0;
		return (doxod + rasxod);
	}

	int getChistayaPribil() {
		if (!is_gos_company && oborot < 5000000)return 0;
		else if (is_gos_company)return 0;
		return (doxod - rasxod);
	}

	std::string getIsGos() {
		if (is_gos_company)return "Государственная";
		else if (!is_gos_company)return "Частная";
	}

	Company& setName(std::string _name) {
		name = _name;
		return *this;
	}

	Company& setRasxod(int _rasxod) {
		if (_rasxod < 0)setRasxod(_rasxod);
		rasxod += _rasxod;
		oborot += _rasxod;
		return *this;
	}
	Company& setDoxod(int _doxod) {
		if (_doxod < 0)setDoxod(_doxod);
		doxod += _doxod;
		oborot += _doxod;
		return *this;
	}
	
	void show() {
		std::cout << "\nНазвание: " << getName();
		std::cout << "\nДоходы: " << getDoxod();
		std::cout << "\nРасходы: " << getRasxod();
		std::cout << "\nОборот: " << getOborot();
		std::cout << "\nЧистая прибыль: " << getChistayaPribil();
		std::cout << "\nВид: " << getIsGos() << std::endl;
	}
};

int main() {
	system("chcp 1251");
	std::vector <Company> companies;
	int blades = 0;
	do {
		system("pause"); system("cls");
		std::cout << "Компании: ";
		for (int i = 0; i < companies.size(); i++) {
			std::cout << companies.at(i).getName() << " ";
		}
		std::cout << "\n\n1.Добавить компанию\n2.Изменить название\n3.Добавить доход\n4.Добавить расход\n5.Вывести все компании\n6.Выход\n>_";
		std::cin >> blades;
		std::string name;
		switch (blades) {
		case 1: {
			companies.push_back(Company().setCompany());
			break;
		}
		case 2: {
			std::cout << "Введите название: "; std::cin >> name;
			for (int i = 0; i < companies.size(); i++) {
				if (companies.at(i).getName() == name) {
					std::cin >> name;
					companies.at(i).setName(name);
				}
			}
			break;
		}
		case 3: {
			int doxod;
			std::cout << "Введите название: "; std::cin >> name;
			for (int i = 0; i < companies.size(); i++) {
				if (companies.at(i).getName() == name) {
					std::cout << "Введите доход: "; std::cin >> doxod;
					companies.at(i).setDoxod(doxod);
				}
			}
			break;
		}
		case 4: {
			std::cout << "Введите название: "; std::cin >> name;
			for (int i = 0; i < companies.size(); i++) {
				if (companies.at(i).getName() == name) {
					int rasxod;
					std::cout << "Введите расход: "; std::cin >> rasxod;
					companies.at(i).setRasxod(rasxod);
				}
			}
			break;
		}
		case 5: {
			for (int i = 0; i < companies.size(); i++) {
				companies.at(i).show();
			}
			break;
		}
		case 6: {
			break;
		}
		}
	} while (blades != 0);
}