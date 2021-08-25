// Find square if less than 50, else check odd or even.

#include<stdio.h>
#include<conio.h>
int main()
{
    int a;
    printf("Enter a number = ");
    scanf("%d",&a);

    if(a<=50)
        printf("The square of %d is %d",a,a*a);
    else
        printf("The number %d is %s",a,(a%2==0)?"Even":"Odd");

    getch();
    return 0;
}
