#include <iostream>

using namespace std;

void crypt(char* raw, uint8_t key[]){
    // Variables locales
    const int m = 256;
    uint8_t buffer[3];

    // Actions
    buffer[0] = (uint8_t)(((key[0] * raw[0]) + (key[1] * raw[1]) + (key[2] * raw[2])) % m) ;
    buffer[1] = (uint8_t)(((key[3] * raw[0]) + (key[4] * raw[1]) + (key[5] * raw[2])) % m);
    buffer[2] = (uint8_t)(((key[6] * raw[0]) + (key[7] * raw[1]) + (key[8] * raw[2])) % m);

    // Copy output
    raw[0] = buffer[0];
    raw[1] = buffer[1];
    raw[2] = buffer[2];
}
