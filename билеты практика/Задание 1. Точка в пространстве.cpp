#include <iostream>
#include <vector>

class Point {
	std::string name;
	int x, y, z;
public:
	Point() {
		name = "point";
		x = rand() % 10;
		y = rand() % 10;
		z = rand() % 10;
	}

	Point(std::string name, int x, int y, int z) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void redact() {
		std::cout << "������� ��������: "; std::cin >> name;
		std::cout << "������� X: "; std::cin >> x;
		std::cout << "������� Y: "; std::cin >> y;
		std::cout << "������� Z: "; std::cin >> z;
	}

	void print() {
		std::cout << "��������: " << name << "\nX: " << x << "\nY: " << y << "\nZ: " << z << "\n\n";
	}
};

int main() {

	srand(time(NULL)); system("chcp 1251");
	int blades = 0;
	std::vector <Point> points(3);

	do {
		system("pause"); system("cls");
		std::cout << "1. �������� ���\n2. ��������\n3. ��������\n4. �������\n5. �����\n>_"; std::cin >> blades;
		switch (blades) {
			case 1: {
				for (int i = 0; i < points.size(); i++) {
					std::cout << i << "."; points.at(i).print();
				}
				break;
			}
			case 2: {
				int a;
				std::cout << "������� id: "; std::cin >> a;
				points.at(a).redact();
				break;
			}
			case 3: {
				Point p;
				points.push_back(p);
				std::cout << "����� ���������";
				break;
			}
			case 4: {
				points.pop_back();
				break;
			}
		}
	} while (blades != 0);
}