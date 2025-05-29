#include <iostream>

class MyArray {
	int* address;
	int size;
public:
	MyArray() {
		size = rand() % 10;
	}
	MyArray(int size) {
		this->size = size;
	}
	~MyArray() {
		std::cout << "\nyaica\n";
	}
	const int& operator[] (int index) const{
		return address[index];	
	}

	friend std::ostream& operator<< (std::ostream& out, const MyArray& arr) {
		for (int i = 0; i < arr.size; i++) {
			out << arr.address[i] << " ";
		}
		return out;
	}
};

int main() {

}