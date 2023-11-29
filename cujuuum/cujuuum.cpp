#include <cstdint>
uint64_t joinVal, val = 0x12345678;

void setup() {
	Serial.begin(9600);

	uint8_t* splitVal = (uint8_t*)&val;
	uint8_t* pointer = (uint8_t*)&joinVal;
	while (*splitVal) *pointer++ = *splitVal++;

	Serial.println(joinVal);
}

void loop() {
}
