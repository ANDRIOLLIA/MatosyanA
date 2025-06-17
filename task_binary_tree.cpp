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

public:
    BinaryTree() : root{ nullptr } {}
    std::shared_ptr<Node> getRoot() const {
        return root;
    }

    BinaryTree& add(int val) {
        if (!root) { root = std::make_shared<Node>(val); return *this; }
        std::shared_ptr<Node> current = root;
        bool is_added = false;
        while (!is_added) {
            if (val > *current->data) {
                if (current->right) { current = current->right; }
                else { current->right = std::make_shared<Node>(val); return *this; }
            }
            else {
                if (current->left) current = current->left;
                else { current->left = std::make_shared<Node>(val); return *this; }
            }
        }
    }

    void preOrder(std::shared_ptr<Node> root) {
        if (!root) return;
        std::cout << *root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(std::shared_ptr<Node> root) {
        if (!root) return;
        postOrder(root->left);
        postOrder(root->right);
        std::cout << *root->data << " ";
    }

    void inOrder(std::shared_ptr<Node> root) {
        if (!root) return;
        inOrder(root->left);
        std::cout << *root->data << " ";
        inOrder(root->right);
    }


    int find(int val) {
        std::shared_ptr<Node> current = root;
        int id = 0;
        while (current) {
            if (val == *current->data) {
                return val;
            }
            else if (val < *current->data) {
                current = current->left;
            }
            else {
                ++id;
                current = current->right;
            }
        }
        return 0;
    }
};

int main() {
    BinaryTree binary_tree;
    binary_tree.add(18).add(99).add(2).add(-19).add(20).add(44).add(-5).add(0).add(1).add(88).add(-3).add(3).add(90);
    std::cout << "pre order: ";
    binary_tree.preOrder(binary_tree.getRoot());
    std::cout << "\n\npost order: ";
    binary_tree.postOrder(binary_tree.getRoot());
    std::cout << "\n\nin order: ";
    binary_tree.inOrder(binary_tree.getRoot());

    std::cout << "\n\nfind: " << binary_tree.find(20);
}