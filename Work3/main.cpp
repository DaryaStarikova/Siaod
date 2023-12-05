#include "hash_table.h"

int main() {
    HashTable hashTable(10, hashFunction, doubleHashFunction);

    DisciplineLoad load1 = { 101, 201, "Mathematics", 1 };
    DisciplineLoad load2 = { 102, 202, "Computer Science", 2 };
    DisciplineLoad load3 = { 103, 203, "Physics", 1 };

    hashTable.insert(1, load1);
    hashTable.insert(2, load2);
    hashTable.insert(3, load3);

    hashTable.print();

    int index = hashTable.find(2);
    if (index != -1) {
        cout << "Key 2 found at index " << index << endl;
    }
    else {
        cout << "Key 2 not found." << endl;
    }

    hashTable.remove(2);

    index = hashTable.find(2);
    if (index != -1) {
        cout << "Key 2 found at index " << index << endl;
    }
    else {
        cout << "Key 2 not found." << endl;
    }

    hashTable.print();

    hashTable.rehash();
    hashTable.print();

    return 0;
}
