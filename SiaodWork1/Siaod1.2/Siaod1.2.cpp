#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int inputValue;
    cout << "Введите целое число: ";
    cin >> inputValue;

    int mask = 0xFFFFFFF0; // Маска для обнуления четырех младших бит

    int result = inputValue & mask; // Используем поразрядное И для обнуления битов

    cout << "Исходное значение: " << inputValue << endl;
    cout << "Маска:            " << mask << endl;
    cout << "Результат:        " << result << endl;

    return 0;
}
