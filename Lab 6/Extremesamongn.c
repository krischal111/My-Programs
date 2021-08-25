#include<stdio.h>
#include<conio.h>
int main()
{
    unsigned int n;
    printf("Enter the number of numbers = ");
    scanf("%d",&n);
    int numbers[n],greatest, lowest;
    printf("\nPlease enter the values now: \n");
    for(int i=1; i<=n;i++)
    {
        printf("Number %d = ",i);
        scanf("%d",&numbers[i-1]);
    }

    greatest = lowest = numbers[0];
    
    for(int i = 1; i<n ;i++)
    {
        int thisnumber = numbers[i];
        if (greatest < thisnumber)
        greatest = numbers[i];
        else
        if (lowest > thisnumber)
        lowest = thisnumber;
    }
    printf("\nThe largest number is %d\nThe smallest number is %d.",greatest, lowest);
    getch();
    return 0;
}