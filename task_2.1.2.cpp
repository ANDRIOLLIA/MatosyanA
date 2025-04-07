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
		std::cout << "������� �������� ��������: "; std::cin >> name;
		std::cout << "������� ������: "; std::cin >> doxod;
		std::cout << "������� �������: "; std::cin >> rasxod;
		std::cout << "������� ��������������� �������� ��� ���(1 ��� 0): "; std::cin >> is_gos_company;
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
		if (is_gos_company)return "���������������";
		else if (!is_gos_company)return "�������";
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
		std::cout << "\n��������: " << getName();
		std::cout << "\n������: " << getDoxod();
		std::cout << "\n�������: " << getRasxod();
		std::cout << "\n������: " << getOborot();
		std::cout << "\n������ �������: " << getChistayaPribil();
		std::cout << "\n���: " << getIsGos() << std::endl;
	}
};

int main() {
	system("chcp 1251");
	std::vector <Company> companies;
	int blades = 0;
	do {
		system("pause"); system("cls");
		std::cout << "��������: ";
		for (int i = 0; i < companies.size(); i++) {
			std::cout << companies.at(i).getName() << " ";
		}
		std::cout << "\n\n1.�������� ��������\n2.�������� ��������\n3.�������� �����\n4.�������� ������\n5.������� ��� ��������\n6.�����\n>_";
		std::cin >> blades;
		std::string name;
		switch (blades) {
		case 1: {
			companies.push_back(Company().setCompany());
			break;
		}
		case 2: {
			std::cout << "������� ��������: "; std::cin >> name;
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
			std::cout << "������� ��������: "; std::cin >> name;
			for (int i = 0; i < companies.size(); i++) {
				if (companies.at(i).getName() == name) {
					std::cout << "������� �����: "; std::cin >> doxod;
					companies.at(i).setDoxod(doxod);
				}
			}
			break;
		}
		case 4: {
			std::cout << "������� ��������: "; std::cin >> name;
			for (int i = 0; i < companies.size(); i++) {
				if (companies.at(i).getName() == name) {
					int rasxod;
					std::cout << "������� ������: "; std::cin >> rasxod;
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