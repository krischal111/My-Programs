#include<stdio.h>

int main()
{
    int num=0,rev=0,digits=0,temp=0, sumdigits=0;
    printf("Enter a number. ");
    scanf("%d",&num);

    temp=num;
    while(temp>0)
    {
        rev = rev*10 + temp%10;
        sumdigits += temp%10;
        digits++;
        temp/=10;
    }
    printf("The sum of digits is %d",sumdigits);
    return 0;
}
