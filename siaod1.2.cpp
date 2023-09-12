#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_DIGIT = 10000000; // Максимальное значение семизначного числа

void countingSort(vector<bool>& input, vector<bool>& output) {
    vector<int> count(MAX_DIGIT + 1, 0);

    // Подсчет количества установленных битов (единиц) для каждого числа
    for (int i = 0; i < input.size(); ++i) {
        if (input[i]) {
            count[i]++;
        }
    }

    // Запись отсортированных чисел в выходной массив
    int outputIndex = 0;
    for (int i = 0; i <= MAX_DIGIT; ++i) {
        while (count[i] > 0) {
            output[outputIndex++] = 1;
            count[i]--;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество семизначных чисел: ";
    cin >> n;

    vector<bool> input(n * 7, false); // Исходный массив битов
    vector<bool> sorted(n * 7, false); // Массив для отсортированных чисел

    cout << "Введите " << n << " семизначных чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        long long num;
        cin >> num;

        // Записываем семизначное число в массив битов
        for (int j = 0; j < 7; ++j) {
            input[i * 7 + j] = (num % 10 == 1);
            num /= 10;
        }
    }

    countingSort(input, sorted);

    cout << "Отсортированные семизначные числа:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 6; j >= 0; --j) {
            cout << (sorted[i * 7 + j] ? '1' : '0');
        }
        cout << endl;
    }

    return 0;
}
