#include <iostream>
#include <bitset>


int main() {
    unsigned char MASK = 0b00111100, Data[2] = {0b10100100,0b10110101};
    std::cout << std::bitset<8>(Data[0]) << " ^\t" <<
                 std::bitset<8>(MASK) << " = " <<
                 std::bitset<8>(Data[0] ^ MASK) << std::endl;

    std::cout << std::bitset<8>(Data[0]) << " |\t" <<
                 std::bitset<8>(MASK) << " = " <<
                 std::bitset<8>(Data[0] | MASK) << std::endl;

    std::cout << std::bitset<8>(Data[0]) << " &\t" <<
                 std::bitset<8>(MASK) << " = " <<
                 std::bitset<8>(Data[0] & MASK) << std::endl;

    std::cout << std::bitset<8>(Data[0]) << " &\t" <<
                 std::bitset<8>(~MASK) << " = " <<
                 std::bitset<8>(Data[0] & (~MASK)) << std::endl;

    std::cout << std::bitset<8>(Data[0]) << " & >>2\t" <<
                 std::bitset<8>(MASK) << " = " <<
                 std::bitset<8>( (Data[0] & MASK) >> 2) << std::endl;

    std::cout << std::bitset<8>(Data[0]) << " >>2 &\t" <<
                 std::bitset<8>(MASK) << " = " <<
                 std::bitset<8>((Data[0] >> 2 ) & 0b00111100) << std::endl;

    std::cout << std::bitset<8>(Data[1]) << " & >>2\t" <<
                 std::bitset<8>(MASK) << " = " <<
                 std::bitset<8>( (Data[1] & MASK) >> 2) << std::endl;

    std::cout << std::bitset<8>(Data[0]) << " >>2 &\t" <<
                 std::bitset<8>(MASK) << " = " <<
                 std::bitset<8>((Data[0] >> 2 ) & 0b00111100) << std::endl;                 

    return 0;
}