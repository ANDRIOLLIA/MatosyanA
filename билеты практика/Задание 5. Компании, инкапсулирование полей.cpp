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
	companies.push_back(Company("����", 1001, 100));
	companies.push_back(Company("���� ����", 1001, 100));
	companies.push_back(Company("���� ���� ����", 1001, 100));

	do {
		system("pause"); system("cls");
		std::cout << "\n1.�������� ���\n2.�������������\n0.�����\n>_ "; std::cin >> blades;
		switch (blades) {
		case 1: {
			for (int i = 0; i < companies.size(); i++) {
				std::cout << "id: " << i << "\n��������: " << companies.at(i).getName() << "\n������: " << companies.at(i).getDoxod() <<
					"\n�������: " << companies.at(i).getRasxod() << "\n������: " << companies.at(i).getOborot() << 
					"\n������ �������: " << companies.at(i).getChistayaPribil() << std::endl << std::endl;
			}
			break;
		}
		case 2: {
			int choice;
			std::cout << "1. ������������� ���\n2. ������������� �����\n3. ������������� ������\n>_ "; std::cin >> choice;
			int id;
			std::cout << "������� id ��������: "; std::cin >> id;
			switch (choice) {
			case 1: {
				std::string name;
				std::cout << "������� ���: "; std::cin >> name;
				companies.at(id).setName(name);
				break;
			}
			case 2: {
				int doxod;
				std::cout << "������� �����: "; std::cin >> doxod;
				companies.at(id).setDoxod(doxod);
				break;
			}
			case 3: {
				int rasxod;
				std::cout << "������� ������: "; std::cin >> rasxod;
				companies.at(id).setRashod(rasxod);
				break;
			}
			}
			break;
		}
		}

	} while (blades != 0);
}