#include <iostream>
#include <vector>

class Student {
	std::string name;
	int age, stud_class, id;
	static int amount_of_student;
	bool is_men;

public:
	Student(std::string name, int age, int stud_class, bool is_men) {
		this->name = name;
		this->age = age;
		this->stud_class = stud_class;
		this->amount_of_student = amount_of_student;
		this->is_men = is_men;
	}
	Student() {
		name = "adidas";
		age = 0;
		stud_class = 0;
		is_men = true;
		amount_of_student = id;
		id = id;
		id++;
	}

	Student& setAge(int age) {
		this->age = age;
		return *this;
	}

	Student& setStudClass(int stud_class) {
		this->stud_class = stud_class;
		return *this;
	}

	std::string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	int getStudClass() {
		return stud_class;
	}

	int getAmountOfStudent() {
		return amount_of_student;
	}

	std::string getIsMen() {
		if (is_men)return "Мужчина";
		if (!is_men)return "Женщина";
	}

	void redact() {
		std::cout << "Введите имя: "; std::cin >> name;
		std::cout << "Введите возраст: "; std::cin >> age;
		std::cout << "Введите класс обучения: "; std::cin >> stud_class;
		std::cout << "Введите пол(1/0): "; std::cin >> is_men;
	}

	void show() {
		std::cout << "ID:" << id;
		std::cout << "Имя: " << name;
		std::cout << "Возраст: " << age;
		std::cout << "Класс обучения: " << stud_class;
		std::cout << "Пол: " << getIsMen();
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Student> students;
	students.push_back(Student("Андрей", 10, 4, 1));
	students.push_back(Student("Матосян", 17, 11, 1));
	students.push_back(Student("Крутой", 9, 3, 1));

	int blades = 0, id = 1;

	do {
		std::cout << "\n1.Добавить студента\n2.Редактировать студента\n3.Удалить студента\n4.Вывести всех студентов\n>_"; std::cin >> blades;
		switch(blades) {
		case 1: {
			students.push_back(Student());
			id++;
			break;
		}
		case 2: {
			int edit_by_id;
			std::cout << "Введите id студента: "; std::cin >> edit_by_id;
			for (int i = 0; i < students.size(); i++) {
				students.at(i).redact();
			}
			break;
		}
		case 3: {

		}
		}
	} while (blades != 0);


	return 0;
}