#include <iostream>

class Node {
public:
    std::shared_ptr<int> data;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

    Node(std::shared_ptr<int> val) : data(val), next(nullptr), prev(nullptr) {}
    Node() : data(0), next(nullptr), prev(nullptr) {}
    ~Node() {
        delete &data;
        delete &next;
        delete &prev;
    }
};

class List {
    std::shared_ptr<Node> first;
    std::shared_ptr<Node> last;
    int size;

public:
    List() : first(nullptr), last(nullptr), size(0) {}

    ~List() {
        clear();
    }

    void pushBack(int val) {
        std::shared_ptr<Node> node = std::make_shared<Node>();
        if (first == nullptr) {
            first = last = node;
        }
        else {
            last->next = node;
            node->prev = last;
            last = node;
        }
        ++size;
    }

    void popBack() {
        if (last == nullptr) return;
        std::shared_ptr<Node> to_delete = last;
        last = last->prev;
        if (last) last->next = nullptr;
        else first = nullptr;
        delete &to_delete;
        --size;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            return *first->data;
        }
        std::shared_ptr<Node> current = first;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return *current->data;
    }

    void clear() {
        std::shared_ptr<Node> current = first;
        while (current != nullptr) {
            std::shared_ptr<Node> nextNode = current->next;
            delete &current;
            current = nextNode;
        }
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    friend std::ostream& operator<<(std::ostream& out, List& list) {
        std::shared_ptr<Node> current = list.first;
        while (current != nullptr) {
            out << current->data << ' ';
            current = current->next;
        }
        return out;
    }
};

int main() {
    List l;

    for (int i = 0; i < 1000000; ++i) {
        l.pushBack(i);
    }
    return 0;
}