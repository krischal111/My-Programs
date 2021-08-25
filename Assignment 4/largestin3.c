#include<stdio.h>

int main()
{
    int a,b,c, greatest;
    printf("Enter 3 numbers = ");
    scanf("%d %d %d",&a,&b,&c);
    if (a>b && a>c)
    greatest = a;
    else if (b>c)
    greatest = b;
    else
    greatest = c;

    printf("The greatest number is %d",greatest);
    return 0;
}