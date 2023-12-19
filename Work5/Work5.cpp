#include <iostream>
#include <fstream>

// Структура записи в файле (предполагается, что у вас есть подобная структура в файле)
struct FileRecord {
    int key;  // Ключ
    std::string disciplineName;  // Название дисциплины
};

// Узел бинарного дерева поиска
struct TreeNode {
    FileRecord data;    // Информационная часть узла
    TreeNode* left;     // Левое поддерево
    TreeNode* right;    // Правое поддерево

    // Конструктор для удобства создания узлов
    TreeNode(const FileRecord& record) : data(record), left(nullptr), right(nullptr) {}
};

// Класс "Бинарное дерево поиска"
class BinarySearchTree {
private:
    TreeNode* root;  // Корень дерева

    // Приватные вспомогательные методы для рекурсивных операций
    void insert(TreeNode*& node, const FileRecord& record);
    TreeNode* search(TreeNode* node, int key);
    TreeNode* remove(TreeNode*& node, int key);
    void display(TreeNode* node);

public:
    // Конструктор
    BinarySearchTree() : root(nullptr) {}

    // Методы
    void insert(const FileRecord& record);
    FileRecord* search(int key);
    void remove(int key);
    void display();
};

// Реализация методов класса BinarySearchTree
void BinarySearchTree::insert(TreeNode*& node, const FileRecord& record) {
    if (node == nullptr) {
        node = new TreeNode(record);
    }
    else if (record.key < node->data.key) {
        insert(node->left, record);
    }
    else if (record.key > node->data.key) {
        insert(node->right, record);
    }
    // Если ключ уже существует, можно добавить обработку этого случая
}

TreeNode* BinarySearchTree::search(TreeNode* node, int key) {
    if (node == nullptr || node->data.key == key) {
        return node;
    }

    if (key < node->data.key) {
        return search(node->left, key);
    }

    return search(node->right, key);
}

TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* BinarySearchTree::remove(TreeNode*& node, int key) {
    if (node == nullptr) {
        return node;
    }

    if (key < node->data.key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->data.key) {
        node->right = remove(node->right, key);
    }
    else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        // Узел с двумя детьми: заменяем узел на минимальный узел из правого поддерева
        TreeNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data.key);
    }

    return node;
}

void BinarySearchTree::display(TreeNode* node) {
    if (node != nullptr) {
        display(node->left);
        std::cout << "Key: " << node->data.key << ", Discipline: " << node->data.disciplineName << std::endl;
        display(node->right);
    }
}

void BinarySearchTree::insert(const FileRecord& record) {
    insert(root, record);
}

FileRecord* BinarySearchTree::search(int key) {
    TreeNode* resultNode = search(root, key);
    return (resultNode != nullptr) ? &(resultNode->data) : nullptr;
}

void BinarySearchTree::remove(int key) {
    root = remove(root, key);
}

void BinarySearchTree::display() {
    display(root);
}

int main() {
    // Теперь вы можете использовать класс BinarySearchTree и связанные операции в вашем приложении
    // Замените комментарии в коде соответствующими действиями
    BinarySearchTree bst;

    // Чтение данных из файла и добавление их в дерево
    std::ifstream inputFile("data.txt");
    if (inputFile.is_open()) {
        int key;
        std::string disciplineName;
        while (inputFile >> key >> disciplineName) {
            bst.insert({ key, disciplineName });
        }
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    // Пример поиска записи в дереве
    FileRecord* foundRecord = bst.search(3 /* key */);
    if (foundRecord != nullptr) {
        std::cout << "Record found: Key: " << foundRecord->key << ", Discipline: " << foundRecord->disciplineName << std::endl;
    }
    else {
        std::cout << "Record not found." << std::endl;
    }

    // Пример удаления записи из дерева
    bst.remove(3 /* key */);

    // Пример отображения дерева
    bst.display();

    return 0;
}
