#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int hexValue = 0x3A; // Заданное значение в шестнадцатеричной системе счисления (0x3A = 58 в десятичной системе)

    int mask = 0xAAAAAAAA; // Маска для установки битов с четными номерами в 1 (10101010...)

    int result = hexValue | mask; // Используем поразрядное ИЛИ для установки битов

    cout << "Исходное значение: 0x" << hex << hexValue << endl;
    cout << "Маска:            0x" << hex << mask << endl;
    cout << "Результат:        0x" << hex << result << endl;

    return 0;
}
