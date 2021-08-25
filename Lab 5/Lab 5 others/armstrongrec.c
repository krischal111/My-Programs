#include<stdio.h>
_Bool isArmstrong(int);
int power(int, int);
int numofdigits(int);

int main()
{
    int n;
    printf("Please enter a number ");
    scanf("%d",&n);
    if(isArmstrong(n))
        printf("It is armstrong number");
    else
    printf("The number is not an armstrong number.");
    return 0;
}

_Bool isArmstrong(int number)
{
    int n = numofdigits(number), temp = number, powersum=0;
    // printf("%d  ",n);
    for(int i = 0; i<n; i++)
    {
        powersum += power(temp%10,n);
        temp/=10;
    }
    if(powersum == number)
    return 1;
    else
    return 0;
}

int numofdigits(int n)
{
    if(n==0)
    return 0;
    else
    return 1+numofdigits(n/10);
}
int power(int a, int b)
{
    if(b<=0)
    return 1;
    else
    return a * power(a, b-1);
}