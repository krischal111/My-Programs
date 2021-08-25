#include<stdio.h>
_Bool isPrime(int);

int main()
{
    int num;
    printf("Enter a number. ");
    scanf("%d",&num);
    printf("The prime factors are:");
    for(int i = 2; i<=num; i++)
    {
        if(num%i!=0)
        continue;       // if not a factor, continue to next number
        if(isPrime(i))
        printf("%d ",i);
    }
    return 0;
}

_Bool isPrime(int num)
{
    
    for(int i = 2; i*i<=num; i++)
    {
        if(num%i == 0)
        return 0;
    }
    return 1;
}