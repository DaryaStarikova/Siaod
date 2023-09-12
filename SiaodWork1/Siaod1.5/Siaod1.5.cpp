#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int inputValue;
    cout << "Введите целое число: ";
    cin >> inputValue;

    int n;
    cout << "Введите номер бита, который хотите установить в 1: ";
    cin >> n;

    // Создаем маску, инициализированную единицей в старшем разряде (вариант 2)
    int mask = 1 << (sizeof(int) * 8 - 1);

    // Устанавливаем n-ый бит в 1
    mask = mask >> (n - 1);

    // Используем поразрядные операции для установки бита
    int result = inputValue | mask;

    cout << "Исходное значение: " << inputValue << endl;
    cout << "Маска:            " << mask << endl;
    cout << "Результат:        " << result << endl;

    return 0;
}
