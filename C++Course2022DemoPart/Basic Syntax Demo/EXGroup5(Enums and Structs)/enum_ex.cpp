#include <stdio.h>
#include <iostream>
using namespace std;

enum months{
JAN=1,FEB=2,MAR=3,APR=4,MAY=5,JUNE=6,JULY=7,AUG=8,SEP=9,OCT=10,NOV=11,DEC=12
};

int main()
{
    enum months month;
    char month_name[13][10] = {" ","January","February","March","April","May","June","July","August","September","October","November","December"};
    for(int month = JAN ; month <= DEC ; month++)
    {
        printf("%d %s\n",month,month_name[month]);
    }
    return 0;
}
