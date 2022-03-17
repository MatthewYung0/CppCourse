/*
 ===================================================================================================
 Description : Code to demonstrate the capability of the Bitwise operators on 0101 (5) and 1010 (10)
 ===================================================================================================
 */

#include <stdio.h>

int main()
{
    unsigned char var1 =0x05,var2 =0x0A;
    printf("Result of Andind the two variables: %x\n",var1&var2);
    printf("Result of Oring the two variables: %x\n",var1|var2);
    printf("Result of Xor the two variables: %x\n",var1^var2);
    printf("Result of 1'complement for var1: %x\n",~var1);
    printf("Result of 1'complement for var2: %x\n",~var2);
    return 0;
}
