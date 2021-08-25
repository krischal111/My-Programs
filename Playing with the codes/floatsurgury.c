#include<conio.h>
#include<stdio.h>
int main()
{
    float number;
    long storebits,a,b;
    unsigned char exponent;
    _Bool sign;

    printf("Please input a number = ");
    scanf("%f",&number);
    storebits = (*(long *)&number);                 // Takes bits of number as it is in floating number
    exponent = (storebits>>23)-127;                 // Takes exponent of a number   
    a = ((a << (1+8))>>(1+8)) + 1<<23;              // Takes only mantissa of number, erasing exp, adding 1 at start
    sign = (storebits>>31);                         // Takes the sign of the input number

    printf("The sign is %c, \ncrude number (no decimal or halving accrodingly but with first digit) is %ld\n,",(sign?'-':'+'),a);
    printf(" and the exponent (with base 2) is %d",exponent);
    printf("\n\n");
    getch();
    return 0;
}

void *displaybin()
{
    
}