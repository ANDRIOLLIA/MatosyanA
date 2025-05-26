#include <iostream>

class Test {
	int value;
public:
	Test(int num) :value{ num } {
		std::cout << "Test with " << value << std::endl ;
	}

	~Test() {
		std::cout << "Test with " << value << " destroyed\n";
	}

	Test(const Test& obj) {
		std::cout << "\nCopy constr\n";
		value = obj.value;
	}
	Test(const Test&& obj) {
		std::cout << "\nRval copy\n";
		value = obj.value;
	}
};

Test& testFunc() {
	Test result(-10);
	return result;
}

int main() {
	system("pause");
	Test t(testFunc());

	//Test&& t1 = Test(99);
	//&& при создании - ссылка на правое значение
	system("pause");
}