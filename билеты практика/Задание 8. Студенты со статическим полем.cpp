#include <iostream>
#include <vector>

class Student {
	static int amount_of_student;
	int id, age;
	std::string name, gender;
public:
	Student() {
		++amount_of_student;
		id = amount_of_student;
		age = rand() % 11 + 7;
		name = "Андрей";
		gender = "мужчина";
	}

	Student(int age, std::string name, std::string gender) {
		++amount_of_student;
		id = amount_of_student;
		this->age = age;
		this->name = name;
		this->gender = gender;
	}

	void redact() {
		std::cout << "Введите возраст: "; std::cin >> age;
		std::cout << "Введите имя: "; std::cin >> name;
		std::cout << "Введите пол: "; std::cin >> gender;
	}

	void info() {
		std::cout << "\nId: " << id << "\nВозраст: " << age << "\nИмя: " << name << "\nПол: " << gender << std::endl;
	}

	int getId() const {
		return id;
	}
};

int Student::amount_of_student = 0;


int main() {
	srand(time(NULL)); system("chcp 1251"); system("cls");
	
	std::vector<Student> students;
	students.push_back(Student(18, "Влад", "Мужчина"));
	students.push_back(Student(8, "Андрей", "Мужчина"));
	students.push_back(Student(17, "Настя", "Женщина"));
	
	int blades, choice;
	do {
		system("pause"); system("cls");
		std::cout << "1 - Вывести всех\n2 - Добавить студента\n3 - Редактировать студента\n4 - Удалить студента\n0 - Выход\n>_ ";
		std::cin >> blades;
		switch(blades) {
		case 1: {
			for (int i = 0; i < students.size(); i++) {
				students.at(i).info();
			}
			break;
		}
		case 2: {
			students.push_back(Student());
			break;
		}
		case 3: {
			std::cout << "Введите id студента: "; std::cin >> choice;
			students.at(choice - 1).redact();
			break;
		}
		case 4: {
			std::cout << "Введите id студента: "; std::cin >> choice;
			students.erase(students.begin() + choice - 1);
		}
		}
	} while (blades != 0);
}