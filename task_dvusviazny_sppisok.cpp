#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class List {
    Node* first;
    Node* last;
    int size;

public:
    List() : first(nullptr), last(nullptr), size(0) {}

    ~List() {
        clear();
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
        ++size;
    }

    void popBack() {
        if (last == nullptr) return;
        Node* toDelete = last;
        last = last->prev;
        if (last) last->next = nullptr;
        else first = nullptr;
        delete toDelete;
        --size;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            return first->data;
        }
        Node* current = first;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->data;
    }

    void clear() {
        Node* current = first;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    friend std::ostream& operator<<(std::ostream& out, List& list) {
        Node* current = list.first;
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
    l.popBack();
    return 0;
}