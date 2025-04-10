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
		if (is_men)return "�������";
		if (!is_men)return "�������";
	}

	void redact() {
		std::cout << "������� ���: "; std::cin >> name;
		std::cout << "������� �������: "; std::cin >> age;
		std::cout << "������� ����� ��������: "; std::cin >> stud_class;
		std::cout << "������� ���(1/0): "; std::cin >> is_men;
	}

	void show() {
		std::cout << "ID:" << id;
		std::cout << "���: " << name;
		std::cout << "�������: " << age;
		std::cout << "����� ��������: " << stud_class;
		std::cout << "���: " << getIsMen();
	}
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Student> students;
	students.push_back(Student("������", 10, 4, 1));
	students.push_back(Student("�������", 17, 11, 1));
	students.push_back(Student("������", 9, 3, 1));

	int blades = 0, id = 1;

	do {
		std::cout << "\n1.�������� ��������\n2.������������� ��������\n3.������� ��������\n4.������� ���� ���������\n>_"; std::cin >> blades;
		switch(blades) {
		case 1: {
			students.push_back(Student());
			id++;
			break;
		}
		case 2: {
			int edit_by_id;
			std::cout << "������� id ��������: "; std::cin >> edit_by_id;
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