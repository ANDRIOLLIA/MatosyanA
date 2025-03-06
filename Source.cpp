#include <iostream>
#include <vector>
int main() {
	system("chcp 1251");
	int min, max;
	std::vector<int>minmax(3);
	for (int i = 0; i < 3; i++) {
		std::cout << "Введите число: ";
		std::cin >> minmax.at(i);
	}
	min = max = minmax.front();
	for (int i = 0; i < 3; i++) {
		if (min > minmax.at(i))min = minmax.at(i);
		if (max < minmax.at(i))max = minmax.at(i);
	}
	std::cout << "Минимальное: " << min << "\nМаксимальное: " << max;
	return 0;
}