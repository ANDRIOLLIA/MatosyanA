#include <iostream>

class Test {
	int num1, num2;
public:
	Test() {
		num1 = rand() % 10;
		num2 = rand() % 10;
	}
	Test(int num1, int num2) :num1{ num1 }, num2{ num2 } {}
	friend Test operator+(const Test&, const Test&);
	friend std::ostream& operator<< (std::ostream& out, const Test& obj) {
		out << obj.num1 << " " << obj.num2;
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Test& obj) {
		std::cout << "¬ведите первое число: "; in >> obj.num1;
		std::cout << "¬ведите второе число: "; in >> obj.num2;
		return in;
	}
	
	Test& operator++() {
		num1++;
		return *this;
	}

	Test& operator++(int) {
		num2++;
		return *this;
	}
};

Test operator+(const Test& left, const Test& right) {
	return Test(left.num1 + right.num1, left.num2 + right.num2);
}



int main() {
	system("chcp 1251");
	Test t1, t2;
	std::cin >> ++t1 >> ++t2;
	std::cout << t1++ << std::endl << t2++ << std::endl << t1++ + t2++ << std::endl;
	return 0;
}