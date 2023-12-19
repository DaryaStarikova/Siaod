#include <iostream>
#include <fstream>

// ��������� ������ � ����� (��������������, ��� � ��� ���� �������� ��������� � �����)
struct FileRecord {
    int key;  // ����
    std::string disciplineName;  // �������� ����������
};

// ���� ��������� ������ ������
struct TreeNode {
    FileRecord data;    // �������������� ����� ����
    TreeNode* left;     // ����� ���������
    TreeNode* right;    // ������ ���������

    // ����������� ��� �������� �������� �����
    TreeNode(const FileRecord& record) : data(record), left(nullptr), right(nullptr) {}
};

// ����� "�������� ������ ������"
class BinarySearchTree {
private:
    TreeNode* root;  // ������ ������

    // ��������� ��������������� ������ ��� ����������� ��������
    void insert(TreeNode*& node, const FileRecord& record);
    TreeNode* search(TreeNode* node, int key);
    TreeNode* remove(TreeNode*& node, int key);
    void display(TreeNode* node);

public:
    // �����������
    BinarySearchTree() : root(nullptr) {}

    // ������
    void insert(const FileRecord& record);
    FileRecord* search(int key);
    void remove(int key);
    void display();
};

// ���������� ������� ������ BinarySearchTree
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
    // ���� ���� ��� ����������, ����� �������� ��������� ����� ������
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

        // ���� � ����� ������: �������� ���� �� ����������� ���� �� ������� ���������
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
    // ������ �� ������ ������������ ����� BinarySearchTree � ��������� �������� � ����� ����������
    // �������� ����������� � ���� ���������������� ����������
    BinarySearchTree bst;

    // ������ ������ �� ����� � ���������� �� � ������
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

    // ������ ������ ������ � ������
    FileRecord* foundRecord = bst.search(3 /* key */);
    if (foundRecord != nullptr) {
        std::cout << "Record found: Key: " << foundRecord->key << ", Discipline: " << foundRecord->disciplineName << std::endl;
    }
    else {
        std::cout << "Record not found." << std::endl;
    }

    // ������ �������� ������ �� ������
    bst.remove(3 /* key */);

    // ������ ����������� ������
    bst.display();

    return 0;
}
