#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct DisciplineLoad {
    int disciplineCode;
    int programDirectionCode;
    string disciplineName;
    int semesterNumber;
};

struct HashTableElement {
    int key;
    int recordNumber;
    DisciplineLoad disciplineLoad;
    bool isDeleted;
};

struct HashTable {
    vector<HashTableElement> table;
    int size;
    int (*hashFunction)(int, int);
    int (*doubleHashFunction)(int, int, int);

    HashTable(int size, int (*hashFunction)(int, int), int (*doubleHashFunction)(int, int, int));
    void insert(int key, DisciplineLoad disciplineLoad);
    void remove(int key);
    int find(int key);
    void rehash();
    void print();
};

int hashFunction(int key, int size);
int doubleHashFunction(int key, int size, int i);
