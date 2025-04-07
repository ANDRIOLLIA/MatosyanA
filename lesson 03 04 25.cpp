#include <iostream>

class Alpha {
	int num_a, num_b;
public:
	Alpha(int num1, int num2) {
		this->num_a = num1;
		this->num_b = num2;
	}

	// 1. Перегрузка бинарного оператора через глобальную функцию
	friend std::ostream& operator<<(std::ostream& out, const Alpha& obj);

	// 2. Перегрузка бинарного оператора через мтод класса
	const Alpha operator+(const Alpha& other) {
		return Alpha(num_a + other.num_a, num_b + other.num_b);
	}

	// Перегрузка унарного оператора
	const Alpha operator++() {
		num_a++;
		num_b++;
		return *this;
	}

	bool operator==(const Alpha& other) {
		return num_a - other.num_a && num_b == other.num_b;
	}

	int getA() const {
		return num_a;
	}
};

std::ostream& operator<<(std::ostream& out, const Alpha& obj) {

	return out << "a: " << obj.num_a << "; b: " << obj.num_b << ";";
}

void Polymorphysm() {
	Alpha obj_a(5, 3);
	Alpha obj_a(1, 2);
	std::cout << "A - " << obj_a << "\n";
	std::cout << "Alpha - " << obj_a;
}

int main() {
	Polymorphysm();
}