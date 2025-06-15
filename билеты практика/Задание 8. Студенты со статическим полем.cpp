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
		name = "������";
		gender = "�������";
	}

	Student(int age, std::string name, std::string gender) {
		++amount_of_student;
		id = amount_of_student;
		this->age = age;
		this->name = name;
		this->gender = gender;
	}

	void redact() {
		std::cout << "������� �������: "; std::cin >> age;
		std::cout << "������� ���: "; std::cin >> name;
		std::cout << "������� ���: "; std::cin >> gender;
	}

	void info() {
		std::cout << "\nId: " << id << "\n�������: " << age << "\n���: " << name << "\n���: " << gender << std::endl;
	}

	int getId() const {
		return id;
	}
};

int Student::amount_of_student = 0;


int main() {
	srand(time(NULL)); system("chcp 1251"); system("cls");
	
	std::vector<Student> students;
	students.push_back(Student(18, "����", "�������"));
	students.push_back(Student(8, "������", "�������"));
	students.push_back(Student(17, "�����", "�������"));
	
	int blades, choice;
	do {
		system("pause"); system("cls");
		std::cout << "1 - ������� ����\n2 - �������� ��������\n3 - ������������� ��������\n4 - ������� ��������\n0 - �����\n>_ ";
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
			std::cout << "������� id ��������: "; std::cin >> choice;
			students.at(choice - 1).redact();
			break;
		}
		case 4: {
			std::cout << "������� id ��������: "; std::cin >> choice;
			students.erase(students.begin() + choice - 1);
		}
		}
	} while (blades != 0);
}