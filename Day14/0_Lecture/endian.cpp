#include <cstdint>
#include <iostream>


int main() {
    union {
        uint64_t i;
        uint8_t c[8];
    } data;

    data.i = 0x0102030405060708;
    if (data.c[0] == 0x01) {
        std::cout << "Big-endian architecture." << std::endl;
    } else if(data.c[7] == 0x01) {
        std::cout << "Little-endian architecture." << std::endl;
    } else {
        std::cout << "Does not make sense." << std::endl;
    }
    return 0;
}