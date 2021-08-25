/*  To swap the 2 numbers by value
    By: Krischal*/
#include<stdio.h>

void intswap(int a, int b)
{   
    int c;  c = a; a = b; b =c; 
    printf("a = %d, b = %d\n",a,b);
    return;
}

int main()
{
    int a=2,b=3;
    printf("a = %d, b = %d\n", a,b);
    intswap(a,b);
}  
