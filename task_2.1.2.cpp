#include <iostream>
#include <vector>

class Company {
private:
	std::string name;
	double income = 0, expenses = 0;//доходы, расходы
	double turnover = income + expenses, net_profit = income - expenses;//оборот, чистая прибыль
	bool is_gos_company;	
public:
	int id;
	Company() {
		id = 0;
		name = "none";
		income = NULL;
		expenses = NULL;
		turnover = NULL;
		net_profit = NULL;
		is_gos_company = NULL;
	}

	double getIncome() const {
		if (is_gos_company)return 0;
		else if (!is_gos_company && turnover >= 5000000)return income;
		else return 0;
	}
	double getExpenses() const {
		if (is_gos_company)return 0;
		else if (!is_gos_company && turnover >= 5000000)return expenses;
		else return 0;
	}
	double getNetProfit() const {
		if (is_gos_company)return 0;
		else if (!is_gos_company && turnover >= 5000000)return net_profit;
		else return 0;
	}
	double getTurnover() const {
		if (!is_gos_company && turnover >= 5000000)return net_profit;
		else return 0;
	}
	std::string getName() const {
		return name;
	}

	Company& setName(std::string _name) {
		name = _name;
		return *this;
	}
	Company& setIncome(double _income){
		income += _income;
		return *this;
	}
	Company& setExpenses(double _expenses){
		expenses += _expenses;
		return *this;
	}

	void edit() {
		std::cout << "\nname: "; std::cin >> name;
		std::cout << "\nincome: "; std::cin >> income;
		std::cout << "\nexpenses: "; std::cin >> expenses;
		std::cout << "\nis_gos_company: "; std::cin >> is_gos_company;
	}

	void info() {
		std::cout << "\nname: " << name
			<< "\nincome: " << income
			<< "\nexpenses: " << expenses
			<< "\nturnover: " << turnover
			<< "\nnet_profit: " << net_profit;

		if (is_gos_company) { std::cout << "\nis_gos_company: государственная" ; }
		if (!is_gos_company) { std::cout << "\nis_gos_company: не государственная" ; }
	}
};

int main() {
	system("chcp 1251"); system("cls");
	int choice = 0, companies_quantity, ids = 0, input_id = 0;
	std::cout << "Введите количество компаний: "; std::cin >> companies_quantity;
	std::vector<Company>companies;
	for (int i = 0; i < companies_quantity; i++) {
		companies.push_back(Company());
		companies.at(i).id = ids;
		ids++;
	}

	do {
		std::cout << std::endl; system("pause"); system("cls");
		std::cout << "1 - Получить\n2 - Изменить\n>_"; std::cin >> choice;
		if (choice == 1) {
			std::cout << "1 - получить все данные\n2 - получить название компании\n3 - получить оборот\n4 - получить чистую прибыть\n5 - получить доходы\n6 - получить расходы\n>_";
			std::cin >> choice;
			switch (choice) {
			case 1:
				std::cout << "Введите id: "; std::cin >> choice;
				companies.at(choice).info();
				break;
			case 2:
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Название: " << companies.at(choice).getName();
				break;
			case 3:
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Оборот: " << companies.at(choice).getTurnover();
				break;
			case 4:
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Чистая прибыль: " << companies.at(choice).getNetProfit();
				break;
			case 5:
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Доходы: " << companies.at(choice).getIncome();
				break;
			case 6:
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Расходы: " << companies.at(choice).getExpenses();
				break;
			}
		}
		else if (choice == 2) {
			std::cout << "1 - изменить компанию\n2 - изменить название компании\n3 - добавить расходы\n4 - добавить доходы\n>_";
			std::cin >> choice;
			switch (choice) {
			case 1:
				std::cout << "Введите id: "; std::cin >> choice;
				companies.at(choice).edit();
				break;
			case 2: {
				std::string name;
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Введите имя: "; std::cout << name;
				companies.at(choice).setName(name);
				break;
			}
			case 3: {
				double sum = 0;
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Введите сумму: "; std::cin >> sum;
				companies.at(choice).setIncome(sum);
				break;
			}
			case 4: {
				double sum = 0;
				std::cout << "Введите id: "; std::cin >> choice;
				std::cout << "Введите сумму: "; std::cin >>  sum;
				companies.at(choice).setExpenses(sum);
				break;
			}
			}
		}
	} while (true);
}