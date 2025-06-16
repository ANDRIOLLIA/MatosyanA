#include <iostream>

class Queue {
	class Node {
	public:
		std::shared_ptr<int> data;
		std::shared_ptr<Node> next;
		Node(int val) : data{ std::make_shared<int>(val)}, next{ nullptr } {}
	};
	std::shared_ptr<Node> first, last;
public:
	Queue() {
		first = last = nullptr;
	}

	Queue& push(int val) {
		if (!first) { first = last = std::make_shared<Node>(val); return *this; }
		last->next = std::make_shared<Node>(val);
		last = last->next;
		return *this;
	}

	int pop() {
		int data = *first->data;
		first = first->next;
		return data;
	}
	bool isEmpty() { return first == nullptr; }
	
	Queue& clear() {
		while (first) { pop(); }
		last = first = nullptr;
		return *this;
	}
	
	~Queue() {
		clear();
	}
};

int main() {
	Queue q1; std::cout << (q1.isEmpty() ? "\nempty" : "\nnot empty");
	for (int i = 0; i < 100; i++)q1.push(i);
	for (int i = 0; i < 5; i++) {
		std::cout << q1.pop() << " ";
	}
	std::cout << (q1.isEmpty() ? "\nempty" : "\nnot empty");
	for (int i = 0; i < 10; i++) {
		q1.push(i);
	}
	q1.clear();
	std::cout << (q1.isEmpty() ? "\nempty" : "\nnot empty");
}