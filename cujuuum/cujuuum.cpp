#FNN

uint32_t val = 0xFF00FF;//16711935 - фиолетовый
byte splitVal[4]; // массив с байтами
uint32_t joinVal; //собранный из байтов цвет

byte* pointer; // указатель на 1 байт. значение переменной хранится здесь, указывает на первый байт переменной и объявляем его тип.
char text[32]; //
static void setup() { 
    Serial.begin(9600); 
    pointer = (byte*)&val; // указываем на переменную val. берем адресс переменной тип как и указатель (байт), иначе компил. рухнет(

    splitVal[0] = *pointer; // значение по адрессу указателя.
    splitVal[1] = *(pointer+1); // к адресу добавляется единичка и типо +1 байт (переменная занимает 4 байта)
    splitVal[2] = *(pointer+2);
    splitVal[3] = *(pointer+3);
    Serial.println (splitVal[0]); // вводим элементы массива в порт монитор-порта че то в этом роде.
    Serial.println (splitVal[0]);
    Serial.println (splitVal[0]);
    Serial.println (splitVal[0]);
//теперь побайтово
    pointer =(byte*)&joinVal; //указатель на перменную joinVal
    *pointer = splitVal[0]; // вместо считывания в каждую ячейку записываем значение элементов массива,хранящего байты изнач переменной.
    *(pointer+1) = splitVal[1]; //побайтова пишем joinVal
    *(pointer+2) = splitVal[2];
    *(pointer+3) = splitVal[3];

    Serial.println (joinVal, HEX);
}
    
//в принципе этот код увы в последний день догадались( ну вроде рабочий....не ломается....
    
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


