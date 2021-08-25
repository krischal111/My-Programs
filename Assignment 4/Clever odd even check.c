//Clever way to check odd or even
#include<stdio.h>
#include<conio.h>
int main()
{
    int num;
    printf("Enter a number = ");
    scanf("%d",&num);
    if((num&1)==1)
        printf("Your number is odd");
    else 
        printf("Your number is even");
    getch();
    return 0;    
}


/*
Logic: Using bitwise operator to find the last bit.

Fact about even number:
The even number in binary digit always has
a zero at the end.
Examples: 00100, 11010, 010010,110100 are even numbers
whereas 00101, 11011, 010011, 110101 are odd numbers

If we just get the value of last bit, or LSB we can
already guess if its odd or even. If LSB is 0, it is even
If LSB is 1, it is odd.

We know, 1 is represented as 000000001 in binary, and
if we perform bitwise and between 1 and required number,
we get last bit and nothing more. So if that result is equal
to 0, that means the number is even. And if that is 1,
the number is odd.
Voila, we can check if a number is odd or even
without needing to check a reminder, its so easy.
*/