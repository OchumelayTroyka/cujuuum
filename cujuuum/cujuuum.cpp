#include <cstdint>
#include <cstddef>
using namespace std;
uint32_t val = 0xFF00FF;//16711935 - фиолетовый
byte splitVal[7];
uint32_t joinVal;

byte* pointer;

static void setup() {
    Serial.begin(9600);

    pointer = (byte*)&val;
    for (byte; i = 0; i < 3; i++) {
        splitVal[i] = *(pointer + i);
    }

    pointer = (byte*)&joinVal;
    for (byte; i = 0; i < 3; i++) {
        *(pointer + i) = splitVal[i];
    }

    Serial.println(joinVal, HEX);
}

void loop() {
    
}
