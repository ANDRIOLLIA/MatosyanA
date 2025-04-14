#include <iostream>
#include <vector>

class Student {
    std::string name;
    int age;
    int stud_class;
    int id;
    static int amount_of_students;  
    bool is_men;

public:
	Student(int id) {
		name = "adidas";
		age = 0;
		stud_class = 0;
		is_men = true;
		this->id = id;
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

    std::string getIsMen() {
        return is_men ? "Мужчина" : "Женщина"; 
    }

	int getID() {
		return id;
	}

    void redact() {
        std::cout << "Введите имя: "; std::cin >> name;
        std::cout << "Введите возраст: "; std::cin >> age;
        std::cout << "Введите класс обучения: "; std::cin >> stud_class;
        std::cout << "Введите пол(1/0): "; std::cin >> is_men;
    }

    void show() {
        std::cout << "\nID: " << id;
        std::cout << "\nИмя: " << name;
        std::cout << "\nВозраст: " << age;
        std::cout << "\nКласс обучения: " << stud_class;
        std::cout << "\nПол: " << getIsMen() << std::endl;
    }
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Student> students;

	int blades = 0, id = 0, edit_by_id;

	do {
		system("pause"); system("cls");
		if (id >= 1) {
			std::cout << "Студенты: \n";
			for (int i = 0; i < students.size(); i++) {
				std::cout << students.at(i).getID() << " - " << students.at(i).getName() << std::endl;
			}
		}
		std::cout << "\n1.Добавить студента\n2.Редактировать студента\n3.Удалить студента\n4.Вывести всех студентов\n>_"; std::cin >> blades;
		switch(blades) {
		case 1: {
			students.push_back(Student(id));
			id++;
			break;
		}
		case 2: {
			std::cout << "Введите id студента: "; std::cin >> edit_by_id;
			students.at(edit_by_id).redact();
			break;
		}
		case 3: {
			std::cout << "Введите id студента: "; std::cin >> edit_by_id;
			students.erase(students.begin() + edit_by_id);
			break;
		}
		case 4: {
			std::cout << "Количество студентов: " << id;
			for (int i = 0; i < students.size(); i++) {
				students.at(i).show();
			}
			break;
		}
		}
	} while (blades != 0);
	return 0;
}