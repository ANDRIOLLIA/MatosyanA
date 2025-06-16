#include <iostream>

class BinaryTree {
	class Node {
	public:
		std::shared_ptr<int> data;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
		Node(int val) : data{ std::make_shared<int>(val) } { left = right = nullptr; }
	};
	std::shared_ptr<Node> root;
	void preOrder(std::shared_ptr<Node> current) {}
public:
	BinaryTree():  root { nullptr }{}
	BinaryTree& add(int val) {
		if (!root) { root = std::make_shared<Node>(val); return *this; }
		std::shared_ptr<Node>current = root;
		bool is_added = false;
		while (!is_added) {
			if (val > * current->data) {
				if (current->right) current = current->right;
				else { current->right = std::make_shared<Node>(val); is_added = true; }
			}
		}
	}
	void preOrder() {}
	int find(int val) {}
};

int main() {

}