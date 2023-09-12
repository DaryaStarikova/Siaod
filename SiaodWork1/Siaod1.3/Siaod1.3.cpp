#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int inputValue;
    cout << "Введите целое число: ";
    cin >> inputValue;

    int multiplier = 16; // Множитель

    int result = inputValue << 4; // Умножение на 16 с помощью сдвига влево на 4 бита

    cout << "Исходное значение: " << inputValue << endl;
    cout << "Множитель:        " << multiplier << endl;
    cout << "Результат:        " << result << endl;

    return 0;
}