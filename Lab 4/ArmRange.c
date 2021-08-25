// To check armstrong number in a range

#include<stdio.h>
#include<conio.h>
#include<math.h>

int intswap(int *a, int *b)
{
    int swap=*a;
    *a = *b;
    *b = swap;
}

int main()
{
    int num1,num2,num,temp,digit,flag,numofdigits;
    long int powersum;
    printf("Enter two numbers = ");
    scanf("%d %d",&num1,&num2);

    printf("The armstrong numbers are ");
    if(num1>num2)    intswap(&num1,&num2);

for(num = num1; num<=num2; num++)//Checking and printing armstr number in the range
{
    
    
    //counting number of digits
    temp=num;
    numofdigits=0;
    while(temp!=0)
    {
        numofdigits++;
        temp/=10;
    }

    //applying armstrong formula
    temp = num;
    powersum=0;
    while(temp!=0)
    {
        digit=temp%10;
        powersum+=pow(digit,numofdigits);
        temp/=10;
    }

    //checking armstrong and printing if true
    if(powersum==num)
    printf("%d ",num);
}
    getch();
    return 0;
}