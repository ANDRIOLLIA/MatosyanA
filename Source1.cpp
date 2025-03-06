#include <iostream>

int main() {
	system("chcp 1251");
	int choice, size;
	std::cout << "Введите размер массива: "; std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		std::cout << "Введите число: "; std::cin >> arr[i];
	}
	std::cout << "1.По возрастанию\n2.По убыванию\n>_"; std::cin >>  choice;
	
	system("cls");
	std::cout << std::endl << "Заданный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	
	switch (choice) {
	case 1: {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
		break;
	}
	case 2: {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1 - i; j++) {
				if (arr[j] < arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
		break;
	}
	}

	std::cout << std::endl << "Отсортированый массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}


	return 0;
}