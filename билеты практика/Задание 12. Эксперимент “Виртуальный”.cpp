#include <iostream>
#include <vector>

class Old {
public:
	virtual void info(){
		std::cout << "Old";
	}
};

class Nouveau :public Old{
public:
	void info() override {
		std::cout << "\nNouveau";
	}
};

int main() {
	std::vector<std::shared_ptr<Old>> vect;
	vect.push_back(std::make_shared<Old>());
	vect.push_back(std::make_shared<Nouveau>());
	for (int i = 0; i < vect.size(); i++) {
		vect.at(i)->info();
	}
}