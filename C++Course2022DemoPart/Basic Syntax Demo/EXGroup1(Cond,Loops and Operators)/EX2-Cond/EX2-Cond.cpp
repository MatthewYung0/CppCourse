/*
 ===================================================================================================
 Description : Code to check if the input number is even or odd
 ===================================================================================================
 */

#include <stdio.h>

int main(void)
{
    int input;
    scanf("%d",&input);
    if((input%2)==0)
        printf("%d is an even number",input);
    else
        printf("%d is an odd number",input);
    return 0;
}