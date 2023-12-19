#include <iostream>
#include <climits>

// класс узел 
class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// класс бинарного дерева
class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    // вставка узла
    void insert(int value) {
        root = insertUtil(root, value);
    }

    // отображение на экране
    void display() {
        displayUtil(root, 0);
    }

    // сумма значений узлов
    void sumPerLevel() {
        std::cout << "Sum of values per level:\n";
        sumPerLevelUtil(root, 0);
    }

    // меняет местами максимальный и минимальный узел 
    void swapMinMaxValues() {
        swapMinMaxValuesUtil(root);
    }

    // высота дерева
    int getHeight() {
        return getHeightUtil(root);
    }

private:
    // вспомогательная функция для вставки узлов
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

    // вспомогательная функция для вывода древа
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

    // вспомогательная функция для поиска суммы
    void sumPerLevelUtil(TreeNode* node, int level) {
        static int sumPerLevel[100] = { 0 }; // Предполагается максимум 100 уровней

        if (node != nullptr) {
            sumPerLevel[level] += node->key;
            sumPerLevelUtil(node->left, level + 1);
            sumPerLevelUtil(node->right, level + 1);
        }

        if (level == 0) {
            for (int i = 0; i < 100 && sumPerLevel[i] != 0; i++) {
                std::cout << "Level " << i << ": " << sumPerLevel[i] << "\n";
            }
        }
    }

    void swapMinMaxValuesUtil(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        // Находим минимальное и максимальное значения в дереве
        int minValue = findMinValue(node);
        int maxValue = findMaxValue(node);

        // Меняем значения узлов с минимальным и максимальным значениями
        swapValues(node, minValue, maxValue);
    }

    // поиск минимального значения
    int findMinValue(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->key;
    }

    // поиск максимального значения
    int findMaxValue(TreeNode* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->key;
    }

    // вспомогательная функция, рекурсивно меняет местами значения
    void swapValues(TreeNode* node, int value1, int value2) {
        if (node != nullptr) {
            if (node->key == value1) {
                node->key = value2;
            }
            else if (node->key == value2) {
                node->key = value1;
            }
            swapValues(node->left, value1, value2);
            swapValues(node->right, value1, value2);
        }
    }

    // вспомогательная функция для поиска высоты
    int getHeightUtil(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            int leftHeight = getHeightUtil(node->left);
            int rightHeight = getHeightUtil(node->right);

            return std::max(leftHeight, rightHeight) + 1;
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
    tree.insert(5);
    tree.insert(22);
    tree.insert(28);
    tree.insert(14);
    tree.insert(44);

    // Отображаем дерево
    tree.display();

    // Выводим сумму значений по уровням
    tree.sumPerLevel();

    // Меняем местами значения минимального и максимального узлов
    tree.swapMinMaxValues();

    // Отображаем дерево после замены значений
    std::cout << "\nTree after swapping min and max values:\n";
    tree.display();

    // Определяем высоту дерева
    int height = tree.getHeight();
    std::cout << "\nHeight of the tree: " << height << "\n";

    return 0;
}
