#include <iostream>
#include <vector>

class Company {
	int doxod, rasxod, oborot, chistaya_pribil;
public:
	Company(int doxod, int rashod) {
		this->doxod = doxod;
		this->rasxod = rashod;
		oborot = doxod + rasxod;
		chistaya_pribil = doxod - rasxod;
	}

	Company& setDoxod(int doxod) {
		this->doxod = doxod;
		return *this;
	}

	int getDoxod() const {
		if (oborot < 1000000) {
			return 0;
		}
		else {
			return doxod;
		}
	}

	Company& setRasxod(int rashod) {
		this->rasxod = rashod;
		return *this;
	}

	int getRasxod() const {
		if (oborot < 1000000) {
			return 0;
		}
		else {
			return rasxod;
		}
	}

	int getOborot() const {
		if (oborot < 1000000) {
			return 0;
		}
		else {
			return oborot;
		}
	}
	
	int getChistayaPribil() const {
		if (oborot < 1000000) {
			return 0;
		}
		else {
			return chistaya_pribil;
		}
	}
};

int main() {
	system("chcp 1251"); system("cls");

	int doxod, rasxod;

	std::cout << "Введите доходы: "; std::cin >> doxod;
	std::cout << "Введите расходы: "; std::cin >> rasxod;
	
	Company company = Company(doxod, rasxod);

	system("cls");

	std::cout << "Доходы: ";
	if (company.getDoxod() == 0) {
		std::cout << "скрыто";
	} else {
		std::cout << company.getDoxod();
	}
	
	std::cout << "\nРасходы: ";
	if (company.getRasxod() == 0) {
		std::cout << "скрыто";
	} else {
		std::cout << company.getRasxod();
	}
	
	std::cout << "\nОборот: ";
	if (company.getOborot() == 0) {
		std::cout << "скрыто";
	} else {
		std::cout << company.getOborot();
	}
	
	std::cout << "\nЧистая прибыль: ";
	if (company.getChistayaPribil() == 0) {
		std::cout << "скрыто";
	} else {
		std::cout << company.getChistayaPribil();
	}
}