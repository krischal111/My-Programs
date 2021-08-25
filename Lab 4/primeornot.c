//To check prime numbers

#include<conio.h>
#include<stdio.h>
#include<math.h>
int main(){
    int a,flag,d;
    flag = 0;
    printf("Enter a number = ");
    scanf("%d",&a);
    
    for(int i=2;i<=sqrt(a);i++)    
    if(a%i==0) 
    {
        flag=-1;
        d=i;
        break;
    }
    
    if(flag)
    printf("Your number is not a prime and divisible by %d",d);
    else
    printf("Your number is prime");

    getch();

}