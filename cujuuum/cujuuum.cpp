
void loop() {


}
    
#include <iostream>
#include <string>
// Вызываем библиотеки iostream (для ввода-вывода данных) и string (для работы со строками)

    union NumberSplitter {
    int intValue;
    float floatValue;
    double doubleValue;
    unsigned char byteValue[sizeof(double)];
};
// Объявляем объединение NumberSplitter , содержащее переменные типов int, float, double и массив byteValue типа «беззнаковый символ», размер которого равен размеру типа double, то есть в будущем он хранит число по-циферно.
int main() {
    NumberSplitter splitter;
    std::cout << "Enter a number: ";
// Создание переменной splitter из объединения NumberSplitter

    std::cin >> splitter.doubleValue;
//Запрос ввода числа у пользователя и его запись в область doubleValue в объединении

    std::cout << "Bytes: ";
    for (size_t i = 0; i < sizeof(splitter.byteValue); i++) {
        std::cout << static_cast<int>(splitter.byteValue[i]) << " ";
    }
    std::cout << std::endl;
// Объявление цикла for, который проходит по всему числу и вывод по-циферно записанного числа
    std::cout << "Bits: ";
    for (size_t i = 0; i < sizeof(splitter.byteValue); i++) {
        for (int j = 7; j >= 0; --j) {
            std::cout << ((splitter.byteValue[i] >> j) & 1);
        }
   // Объявления цикла for, который проходит по всему числу, и объявление вложенного цикла for, проводящего 7 итераций
        std::cout << " ";
        //Печать двоичного значения введённого числа
    }
    std::cout << std::endl;

    return 0;


