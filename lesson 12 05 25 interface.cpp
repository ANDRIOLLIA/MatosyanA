#include <iostream>

class ITakable {
public:
	virtual void take() = 0;
};

class QuestNote : public ITakable{
	std::string content;
public:
	QuestNote(std::string content) :content{ content } {}
	void take() override {
		std::cout << "������� �������: " << content << std::endl;
	}
};

class Stone : public ITakable{
	std::string material;
public:
	Stone(std::string material) :material{ material } {}
	void take() override {
		std::cout << "������ ��: " << material << std::endl;
	}
};

class Player {
	std::string name;
public:
	Player(std::string name) :name{ name } {}
	void takeIt(std::shared_ptr<ITakable> item) {
		std::cout << name << " �������� ";
		item->take();
	}
};

int main() {
	system("chcp 1251");
	Player p1("����");
	std::shared_ptr<QuestNote> n1 = std::make_shared<QuestNote>("��� ��������, ��� _____");
	std::shared_ptr<Stone> s1 = std::make_shared<Stone>("�����");
	p1.takeIt(n1);
	p1.takeIt(s1);
}