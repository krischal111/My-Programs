/*  To find the factorial of a number by use of recursive function
    By: Krischal*/

#include<stdio.h>
#include<conio.h>
int factorial(int);
int main(){
     int f,a;
    printf("Enter a number = ");
    scanf("%d",&a);
    f=factorial(a);
    if(f!=-1)
        printf("Your factorial is %d\n",f);
    else
    printf("\nPlease supply a positive number");
    getch();
}
int factorial(int i)
{
    if(i==0)
        return 1;
    else if(i>0)
        return i*factorial(i-1);
    else
    return (-1);
}