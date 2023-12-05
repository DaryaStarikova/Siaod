#include "hash_table.h"

HashTable::HashTable(int size, int (*hashFunction)(int, int), int (*doubleHashFunction)(int, int, int)) {
    this->size = size;
    this->hashFunction = hashFunction;
    this->doubleHashFunction = doubleHashFunction;
    this->table = vector<HashTableElement>(size);
    for (int i = 0; i < size; ++i) {
        this->table[i].isDeleted = true;
    }
}

void HashTable::insert(int key, DisciplineLoad disciplineLoad) {
    int index = hashFunction(key, size);
    int i = 0;
    while (!table[index].isDeleted && i < size) {
        index = doubleHashFunction(key, size, i);
        i++;
    }
    if (i == size) {
        cout << "Table is full, can't insert key " << key << endl;
        return;
    }
    table[index].key = key;
    table[index].recordNumber = index;
    table[index].disciplineLoad = disciplineLoad;
    table[index].isDeleted = false;
    cout << "Key " << key << " inserted at index " << index << endl;
}

void HashTable::remove(int key) {
    int index = find(key);
    if (index != -1) {
        table[index].isDeleted = true;
        cout << "Key " << key << " removed." << endl;
    }
    else {
        cout << "Key " << key << " not found." << endl;
    }
}

int HashTable::find(int key) {
    int index = hashFunction(key, size);
    int i = 0;
    while (i < size && !table[index].isDeleted && table[index].key != key) {
        index = doubleHashFunction(key, size, i);
        i++;
    }
    if (i == size || table[index].isDeleted) {
        return -1;
    }
    return index;
}

void HashTable::rehash() {
    int newSize = size * 2;
    HashTable newTable(newSize, hashFunction, doubleHashFunction);
    for (int i = 0; i < size; ++i) {
        if (!table[i].isDeleted) {
            newTable.insert(table[i].key, table[i].disciplineLoad);
        }
    }
    size = newSize;
    table = newTable.table;
}

void HashTable::print() {
    for (int i = 0; i < size; ++i) {
        if (!table[i].isDeleted) {
            cout << "Index: " << i << ", Key: " << table[i].key
                << ", Discipline Code: " << table[i].disciplineLoad.disciplineCode
                << ", Program Direction Code: " << table[i].disciplineLoad.programDirectionCode
                << ", Discipline Name: " << table[i].disciplineLoad.disciplineName
                << ", Semester Number: " << table[i].disciplineLoad.semesterNumber << endl;
        }
    }
}

int hashFunction(int key, int size) {
    return key % size;
}

int doubleHashFunction(int key, int size, int i) {
    int h1 = key % size;
    int h2 = 1 + (key % (size - 1));
    return (h1 + i * h2) % size;
}
