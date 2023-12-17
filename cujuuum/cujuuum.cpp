#FNN
#include <iostream>
using namespace std;
int main()
{
    cout << "Anime top\n";
}

u8 CountOnes1 (u8 n) {
  u8 res = 0;
  while (n) {
    res ++;
    n &= n-1;  // откусывается 1 бит и суммируются откусанные биты (младшие). Но эта штука не работает в 32 и 64...числа большие...
  }
  return res;
}
uint32_t val = 0xFF00FF;//16711935 - фиолетовый
byte splitVal[4]; // массив с байтами
uint32_t joinVal;

byte* pointer; // указатель. значение переменной хранится здесь, указывает на первый байт переменной и объявляем его тип.

static void setup() { 
    Serial.begin(9600); 
    pointer = (byte*)&val; // указываем на переменную val

    splitVal[0] = *pointer;
    splitVal[1] = *(pointer+1); // к адресу добавляется единичка и типо +1 байт
    splitVal[2] = *(pointer+2);
    splitVal[3] = *(pointer+3);
    Serial.println (splitVal[0]); // вводим элементы массива в порт монитор-порта че то в этом роде.
    Serial.println (splitVal[0]);
    Serial.println (splitVal[0]);
    Serial.println (splitVal[0]);

    
void loop() {)


}
#Работает для флоат хотя через раз...печально... последний день( без зачета останемся что ли...только додумались
    
#include <iostream>
#include <string>

    union NumberSplitter {
    int intValue;
    float floatValue;
    double doubleValue;
    unsigned char byteValue[sizeof(double)];
};

int main() {
    NumberSplitter splitter;
    std::cout << "Enter a number: ";

    std::cin >> splitter.doubleValue;

    std::cout << "Bytes: ";
    for (size_t i = 0; i < sizeof(splitter.byteValue); i++) {
        std::cout << static_cast<int>(splitter.byteValue[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "Bits: ";
    for (size_t i = 0; i < sizeof(splitter.byteValue); i++) {
        for (int j = 7; j >= 0; --j) {
            std::cout << ((splitter.byteValue[i] >> j) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;


