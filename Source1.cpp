#include <iostream>

int main() {
	system("chcp 1251");
	int choice, size;
	std::cout << "������� ������ �������: "; std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		std::cout << "������� �����: "; std::cin >> arr[i];
	}
	std::cout << "1.�� �����������\n2.�� ��������\n>_"; std::cin >>  choice;
	
	system("cls");
	std::cout << std::endl << "�������� ������: ";
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

	std::cout << std::endl << "�������������� ������: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}


	return 0;
}