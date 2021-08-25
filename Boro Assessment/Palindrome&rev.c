// To check if number is a palindrome

#include<stdio.h>
#include<conio.h>
int main(){
    int rollnum,temp,last_digit=0,rev=0,a,b,digits;
    printf("Enter your roll number = ");
    scanf("%d",&rollnum);
    temp=rollnum;
    while(temp!=0)
    {
        // since temp/10 is an integer, it perfly separate out last digit
        last_digit = temp%10;
        rev=10*rev+last_digit;
        temp/=10;
        digits++;
    }
    if(rev==rollnum)
    printf("Your roll number is a palindrome.");
    else
    printf("Your roll number is not a palindrome.");
    getch();
    return 0;
}