// To find the reverse of a number and check if number is a palindrome

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
    printf("The reverse number is %d\n",rev);
    if(rev==num)
    printf("Your number is a palindrome.");
    else
    printf("Your number is not a palindrome.");
    getch();
    return 0;
}