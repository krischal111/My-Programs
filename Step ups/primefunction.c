// Prime or not using function

#include<stdio.h>
_Bool isPrime(int);

int main()
{
    int a;
    printf("Enter a number = ");
    scanf("%d",&a);
    if(isPrime(a))
        printf("The number is a prime number.");
    else 
    printf("The number is not a prime number.");
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