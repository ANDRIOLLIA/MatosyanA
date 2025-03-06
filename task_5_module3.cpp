#include <iostream>

int main() {
	system("chcp 1251"); srand(time(NULL));
	int size, userChoice = -1;
	std::cout << "������� ������ �������: "; std::cin >> size;
	int** arr2 = new int* [size];
	for (int i = 0; i < size; i++) {
		arr2[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr2[i][j] = rand() % 19;
		}
	}
	system("cls");
	while (userChoice != 0) {
		system("pause"); system("cls");
		std::cout << "�������:\n1.������\n2.����� ���������� ���������\n3.���������� � ���������� ��������\n4.������ ��������\n0.�����\n>";
		std::cin >> userChoice;
		switch (userChoice) {
		case 1:
		{
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					std::cout << arr2[i][j] << " ";
				}
				std::cout << std::endl;
			}
			break;
		}
		case 2:
			std::cout << "���������� ��������� � �������: " << size * size << std::endl;
		case 3:
		{
			int min, max;
			min = max = arr2[0][0];
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (min > arr2[i][j])min = arr2[i][j];
					if (max < arr2[i][j])max = arr2[i][j];
				}
			}
			std::cout << "�����������: " << min << "\n������������: " << max <<std::endl;
			break;
		}
		case 4:
		{
			for (int i = size - 1; i >= 0; i--) {
				for (int j = size - 1; j >= 0; j--) {
					std::cout << arr2[i][j] << " ";
				}
				std::cout << std::endl;
			}
			break;
		}
		default:
			std::cout << "��" << std::endl;
		}
	}
	return 0;
}