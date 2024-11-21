#include <iostream>
using namespace std;

string ones [] = {"", "один ", "два ", "три ", "четыре ", "пять ", "шесть ", "семь ", "восемь ", "девять "};
string tens [] = {"", "десять ", "двадцать ", "тридцать ", "сорок ", "пятьдесят ", "шестьдесят ", "семьдесят ", "восемьдесят ", "девяносто "};
string teens [] = {"", "одиннадцать ", "двенадцать ", "тринадцать ", "четырнадцать ", "пятнадцать ", "шестнадцать ", "семнадцать ", "восемнадцать ", "девятнадцать "};

string numberToText(int number) {
    string str{""};
    
    if (number == 0) { str.append("нуль "); return str; }
    if (number < 0) { str.append("минус "); number = ~number + 1; }
    if (number >= 11 && number <= 19) { str.append(teens[number - 10]); return str; }
    if (number == 10 || number >= 20) { str.append(tens[number / 10]); number %= 10; }
    if (number >= 1 && number <= 9) { str.append(ones[number]); }

    return str;
}
    

int main() {
    int inputNumber1{};
    int inputNumber2{};

    cout << "Введите целое число: ";
    cin >> inputNumber1;
    cout << "Введите целое число: ";
    cin >> inputNumber2;
    
    if (abs(inputNumber1 >= 100) || abs(inputNumber2) >= 100) {
        cout << "Ошибка! Одно из чисел вне диапазона!" << endl;
        return EXIT_SUCCESS;
    }
    if (inputNumber1 == inputNumber2) { 
        cout << numberToText(inputNumber1) << "равно " << numberToText(inputNumber2); 
    }
    else {
        cout << numberToText(inputNumber1) << (inputNumber1 > inputNumber2 ? "больше, чем " : "меньше, чем ") << numberToText(inputNumber2) << endl;
    }
    
    return EXIT_SUCCESS;
}