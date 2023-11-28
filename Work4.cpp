#include <iostream>

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertUtil(root, value);
    }

    void display() {
        displayUtil(root, 0);
    }

private:
    TreeNode* insertUtil(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->key) {
            node->left = insertUtil(node->left, value);
        }
        else if (value > node->key) {
            node->right = insertUtil(node->right, value);
        }

        return node;
    }

    void displayUtil(TreeNode* node, int level) {
        if (node != nullptr) {
            displayUtil(node->right, level + 1);
            for (int i = 0; i < level; i++) {
                std::cout << "   ";
            }
            std::cout << node->key << "\n";
            displayUtil(node->left, level + 1);
        }
    }
};

int main() {
    BinaryTree tree;

    // Вставляем значения в дерево
    tree.insert(12);
    tree.insert(10);
    tree.insert(25);
    tree.insert(8);

    // Отображаем дерево
    tree.display();

    return 0;
}
