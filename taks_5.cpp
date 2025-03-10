#include <iostream>
#include <string>
#include <vector>

class Worker {
	public:
	int id, age;
	std::string name, gender, post, department;

	Worker() {
		id = 1;
		age = 0;
		name = "noname";
		gender = "undefined";
		post = "undefined";
		department = "undefined";
	}
	Worker(int _id) :Worker() {
		id = _id;
	}
	Worker(int _age, std::string _name) :Worker(_age) {
		name = _name;
	}
	Worker(int _age, std::string _name, std::string _gender) :Worker(_age, _name) {
		gender = _gender;
	}
	Worker(int _age, std::string _name, std::string _gender, std::string _post) :Worker(_age, _name, _gender) {
		post = _post;
	}
	Worker(int _age, std::string _name, std::string _gender, std::string _post, std::string _department) :Worker(_age, _name, _gender, _post) {
		department = _department;
	}

	void redact() {
		std::cout << "Введите возраст: "; std::cin >> age; std::cin.ignore(1, '\n');
		std::cout << "Введите ФИО: "; std::getline(std::cin, name);
		std::cout << "Введите гендер: "; std::cin >> gender;
		std::cout << "Введите должность: "; std::cin >> post;
		std::cout << "Введите отдел: "; std::cin >> department;
	}

	void info() {
		std::cout << "\nID:" << id << "\nВозраст: " << age << "\nИмя: " << name << "\nПол: " << gender << "\nДолжность: " << post << "\nОтдел: " << department;
	}
};

int main() {
	system("chcp 1251");system("cls");
	int choice = 0;
	std::vector<Worker>workers;

	int workers_quan, choice_id, ids = 0;
	std::cout << "Введите количество рабочих: "; std::cin >> workers_quan;
	for (int i = 0; i < workers_quan; i++) {
		workers.push_back(Worker(ids));
		ids++;
	}

	do {
	std::cout << "\n1.Вывсти рабочих\n2.Отредактировать рабочего\n3.Добавить рабочего\n4.Удалить рабочего\n>_"; std::cin >> choice;
	system("cls");
	switch (choice) {
	case 1: {
		  for (int i = 0; i < workers.size(); i++) {
			  workers.at(i).info();
			  std::cout << std::endl;
		}
		  break;
	}
	case 2: {
		std::cout << "Введите ID рабочего: "; std::cin >> choice_id;
		for (int i = 0; i < workers.size(); i++) {
			if (choice_id == workers.at(i).id) {
				workers.at(i).redact();
			}
		}
		break;
	}
	case 3: {
		workers.push_back(Worker(ids));
		ids++;
		break;
	}
	case 4: {
		std::cout << "Введите ID рабочего: "; std::cin >> choice_id;
		for (int i = 0; i < workers.size(); i++) {
			if (choice_id == workers.at(i).id) {
				workers.erase(workers.begin() + i);
			}
		}
		break;
	}
	}
	} while (choice != 0);

	return 0;
}