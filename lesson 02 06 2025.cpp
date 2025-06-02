#include <iostream>

class Node {
	std::shared_ptr<int> data;
	std::shared_ptr<Node> next;
public:
	Node& setData(int value) {
		*data = value;
		return *this;
	}

	Node& setNext(std::shared_ptr<Node> node) {
		next = node;
		return *this;
	}

	int& getData() {
		return *data;
	}

	std::shared_ptr<Node> getNext(){
		return next;
	}

};

class List {
	std::shared_ptr<Node> first, last;
public:
	List() {
		first = last = nullptr;
	}

	List& pushBack(int val) {
		if (!first) first = last = std::make_shared<Node>(val);
		else {
			last->setNext(std::make_shared<Node>(val));
			last = last->getNext();
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, List& list) {
		if (list.first) {
			std::shared_ptr<Node>temp = list.first;
			while (temp) {
				out << temp->getData() << " ";
				temp = temp->getNext();
			}
			return out;
		}
	}
};

int main() {
	List l1;
	l1.pushBack(99).pushBack(18).pushBack(128); std::cout << l1;
}