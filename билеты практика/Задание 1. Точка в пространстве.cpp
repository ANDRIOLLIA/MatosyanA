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
		std::cout << "Введите название: "; std::cin >> name;
		std::cout << "Введите X: "; std::cin >> x;
		std::cout << "Введите Y: "; std::cin >> y;
		std::cout << "Введите Z: "; std::cin >> z;
	}

	void print() {
		std::cout << "Название: " << name << "\nX: " << x << "\nY: " << y << "\nZ: " << z << "\n\n";
	}
};

int main() {

	srand(time(NULL)); system("chcp 1251");
	int blades = 0;
	std::vector <Point> points(3);

	do {
		system("pause"); system("cls");
		std::cout << "1. Показать все\n2. Изменить\n3. Добавить\n4. Удалить\n5. Выход\n>_"; std::cin >> blades;
		switch (blades) {
			case 1: {
				for (int i = 0; i < points.size(); i++) {
					std::cout << i << "."; points.at(i).print();
				}
				break;
			}
			case 2: {
				int a;
				std::cout << "Введите id: "; std::cin >> a;
				points.at(a).redact();
				break;
			}
			case 3: {
				Point p;
				points.push_back(p);
				std::cout << "Точка добавлена";
				break;
			}
			case 4: {
				points.pop_back();
				break;
			}
		}
	} while (blades != 0);
}