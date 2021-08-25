#include<stdio.h>

int main()
{
    int a;
    printf("Enter a number = ");
    scanf("%d",&a);
    for(int i=2;i<=a;i++)
    {
        if(i&1==1) // If LSB of a binary number is 1, it is an odd number
        continue;
        printf("%d ",i);
    }
    return 0;
}