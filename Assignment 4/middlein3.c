#include<stdio.h>

int main()
{
    int a,b,c, middle;
    printf("Enter 3 numbers = ");
    scanf("%d %d %d",&a,&b,&c);
    if (a>b && a<c)
    middle = a;
    else if (b>c && b<a)
    middle = b;
    else
    middle = c;

    printf("The middle number is %d",middle);
    return 0;
}