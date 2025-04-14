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
        return is_men ? "�������" : "�������"; 
    }

	int getID() {
		return id;
	}

    void redact() {
        std::cout << "������� ���: "; std::cin >> name;
        std::cout << "������� �������: "; std::cin >> age;
        std::cout << "������� ����� ��������: "; std::cin >> stud_class;
        std::cout << "������� ���(1/0): "; std::cin >> is_men;
    }

    void show() {
        std::cout << "\nID: " << id;
        std::cout << "\n���: " << name;
        std::cout << "\n�������: " << age;
        std::cout << "\n����� ��������: " << stud_class;
        std::cout << "\n���: " << getIsMen() << std::endl;
    }
};

int main() {
	system("chcp 1251"); system("cls");
	std::vector <Student> students;

	int blades = 0, id = 0, edit_by_id;

	do {
		system("pause"); system("cls");
		if (id >= 1) {
			std::cout << "��������: \n";
			for (int i = 0; i < students.size(); i++) {
				std::cout << students.at(i).getID() << " - " << students.at(i).getName() << std::endl;
			}
		}
		std::cout << "\n1.�������� ��������\n2.������������� ��������\n3.������� ��������\n4.������� ���� ���������\n>_"; std::cin >> blades;
		switch(blades) {
		case 1: {
			students.push_back(Student(id));
			id++;
			break;
		}
		case 2: {
			std::cout << "������� id ��������: "; std::cin >> edit_by_id;
			students.at(edit_by_id).redact();
			break;
		}
		case 3: {
			std::cout << "������� id ��������: "; std::cin >> edit_by_id;
			students.erase(students.begin() + edit_by_id);
			break;
		}
		case 4: {
			std::cout << "���������� ���������: " << id;
			for (int i = 0; i < students.size(); i++) {
				students.at(i).show();
			}
			break;
		}
		}
	} while (blades != 0);
	return 0;
}