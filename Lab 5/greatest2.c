/*  To find the greatest number among 2 numbers
    By: Krischal*/
#include<stdio.h>
int greater(int,int);

int main()
{
    int a,b,c;
    printf("Enter three numbers.");
    scanf("%d %d %d",&a,&b,&c);
    printf("The greatest is %d", greater(greater(a,b),c));
    return 0;
}

int greater(int a, int b)
{   return (a>b)?a:b;   }