#include <iostream>

class Node {
    std::shared_ptr<int> data;
    std::shared_ptr<Node> prev;

public:
    Node(int value) {
        data = std::make_shared<int>(value);
        prev = nullptr;
    }

    int getData() const {
        return *data;
    }

    std::shared_ptr<Node> getPrev() const {
        return prev;
    }

    Node& setData(int value) {
        *data = value;
        return *this;
    }

    Node& setPrev(std::shared_ptr<Node> prev) {
        this->prev = prev;
        return *this;
    }
};

class Stack {
    std::shared_ptr<Node> top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        clear();
    }

    void push(int value) {
        std::shared_ptr<Node> new_node = std::make_shared<Node>(value);
        new_node->setPrev(top);
        top = new_node;
    }


    int pop() {
        int value = top->getData();
        top = top->getPrev();
        return value;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    std::cout << (stack.isEmpty() ? "empty" : "not empty") << std::endl;
    std::cout << "\npush: ";
    for (int i = 1; i <= 100; ++i) { stack.push(i); std::cout << i << " "; }

    std::cout << "\n\npop: ";
    for (int i = 0; i < 5; ++i) {
        int val = stack.pop();
        std::cout << val << " ";
    }

    std::cout << std::endl << (stack.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << "\npush: ";
    for (int i = 0; i < 10; ++i) {
        stack.push(i); std::cout << i << " ";
    }

    stack.clear();
    std::cout << std::endl <<(stack.isEmpty() ? "empty" : "not empty") << std::endl;

    return 0;
}