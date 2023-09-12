#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int inputValue;
    cout << "Введите целое число: ";
    cin >> inputValue;

    int divisor = 32; // Делитель

    int result = inputValue >> 5; // Деление на 32 с помощью сдвига вправо на 5 бит

    cout << "Исходное значение: " << inputValue << endl;
    cout << "Делитель:          " << divisor << endl;
    cout << "Результат:         " << result << endl;

    return 0;
}