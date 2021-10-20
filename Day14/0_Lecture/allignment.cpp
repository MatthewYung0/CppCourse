#include <iostream>

struct Bad_Allignment {
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

struct Good_Allignment {
    uint8_t a;
    uint8_t c;
    uint16_t b;
};

int main() {
    std::cout << "Sizeof Bad_Allignment: " << sizeof(struct Bad_Allignment) << std::endl;
    std::cout << "Sizeof Good_Allignment: " << sizeof(struct Good_Allignment) << std::endl;
}