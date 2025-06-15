#include <iostream>
#include <vector>

class Worker {
	static int id;
	std::string name, gender;
	int age;
public:
	Worker() {
		++id;
		name = "negr";
		gender = "man";
		age = 19;
	}

	Worker(std::string name) {
		id++;
		this->name = name;
	}
	Worker(std::string name, std::string gender) : Worker(name) {
		this->gender = gender;
	}
	Worker(std::string name, std::string gender, int age) : Worker(name, gender) {
		this->age = age;
	}

	void info() {
		std::cout << "\n���: " << name << "\n������: " << gender << "\n�������: " << age;
	}
};

int Worker::id = 0;

int main() {
	system("chcp 1251"); system("cls");
	std::vector<Worker> workers;
	workers.push_back(Worker("������", "�������", 23));
	workers.push_back(Worker("������", "���", 39));
	workers.push_back(Worker("����", "����", 72));

	for (int i = 0; i < workers.size(); i++) {
		workers.at(i).info();
		std::cout << std::endl;
	}
}