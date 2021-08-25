#include<stdio.h>
#include<math.h>

int main()
{
    int binr, temp,thisdigit=0;
    int dec=0;
    printf("Enter a binary number = ");
    scanf("%d",&binr);
    temp=binr;
    for(int i = 0; temp>0; i++)
    {
        thisdigit = temp%10;
        dec += thisdigit?(pow(2,i)):0;
        temp/=10;
    }
    printf("Your decimal number is %d",dec);
    return 0;
}