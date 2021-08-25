// To check strong number

#include<conio.h>
#include<stdio.h>
long int factorial(int);
int main()
{
    int num,temp,digits,digit, factsum;
    printf("Enter a number = ");
    scanf("%d",&num);
    temp = num;
    digits = 0;
    factsum=0;
    while(temp!=0)
    {
        digit = temp - (temp/10)*10;
        factsum+= (int)factorial(digit);
        temp/=10;
    }
    printf("Your number %s a STRONG number", ((factsum == num)?"is":"is not"));
    getch();
    return 0;
}
long int factorial(int i)
{
    if(i==0)
        return 1;
    else if(i>0)
        return i*factorial(i-1);
    else
    return (-1);
}