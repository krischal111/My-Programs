// Check if palindrome

#include<stdio.h>
_Bool isPalindrome(int);

int main()
{
    int a;
    printf("Enter a number = ");
    scanf("%d",&a);
    if(isPalindrome(a))
    {
        printf("The number is a palindrome");
    }
    else
    printf("The number is not a palindrome");
    return 0;
}

_Bool isPalindrome(int a)
{
    int last_digit, rev=0, digits=0;
    int temp=a;
    while(temp!=0)
    {
        last_digit = temp%10;
        rev=10*rev+last_digit;
        temp/=10;
        digits++;
    }
    if (rev==a)
    return 1;
    else
    return 0;
}