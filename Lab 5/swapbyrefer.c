/*  To swap the 2 numbers by reference
    By: Krischal*/
#include<stdio.h>

void intswap(int * a, int * b)
{   int c;  c = *a; *a = *b; *b =c; }

int main()
{
    int a=2,b=3;
    printf("a = %d, b = %d \n", a,b);
    intswap(&a,&b);
    printf("a = %d, b = %d \n", a,b);
}  
