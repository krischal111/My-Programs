// To find reverse of a number

#include<stdio.h>
#include<conio.h>
int main(){
    int num,temp,last_digit=0,rev=0,a,b,digits;
    printf("Enter a number = ");
    scanf("%d",&num);
    temp=num;
    while(temp!=0)
    {
        // since temp/10 is an integer, it perfly separate out last digit
        last_digit = temp%10;
        rev=10*rev+last_digit;
        temp/=10;
        digits++;
    }
    printf("The reverse of your number is %d",rev);
    getch();
    return 0;
}