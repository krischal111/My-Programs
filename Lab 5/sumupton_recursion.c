/*  To find the sum of all natural nubers upto n, by using a recursive functions
    By: Krischal*/

#include<stdio.h>

int sumupto(int n)
{    
    return (n==0)?0:(n+sumupto(n-1)); 
}

int main()
{
    int n;
    printf("Enter a number = ");
    scanf("%d",&n);
    printf("\nThe sum of natural numbers upto %d is %d",n,sumupto(n));
    return 0;
}
