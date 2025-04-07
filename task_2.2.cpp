#include <iostream>
#include <vector>

class Student {
	std::string name;
	int age, stud_class;
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
	Student(int id) {
		name = "adidas";
		age = 0;
		stud_class = 0;
		amount_of_student = id;
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
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Student> students;
	students.push_back(Student("Андрей", 10, 4, 1));
	students.push_back(Student("Матосян", 17, 11, 1));
	students.push_back(Student("Крутой", 9, 3, 1));

	int blades = 0, id = 1;

	do {
		std::cout << "\n1.Добавить студента\n2.Удалить студента\n3.Редактировать\n4.Вывести всех студентов\n>_"; std::cin >> blades;
		switch(blades) {
		case 1: {
			students.push_back(Student(id));
			id++;
		}
		case 2: {
			int edit_by_id;
			std::cout << "Введите id студента: ";
			for (int i = 0; i < students.size(); i++) {

			}
		}
		}
	} while (blades != 0);


	return 0;
}