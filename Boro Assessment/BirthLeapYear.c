// Check if birth year is a leap year

#include<stdio.h>
#include<conio.h>

int main()
{
    int birthyear;
    printf("Enter your birth year.");
    scanf("%d",&birthyear);
    if( (birthyear%400==0) || (birthyear %4 == 0 && birthyear%100 != 0)  )
    printf("Your birth year is a leap year. ");
    else
    printf("Your birth year is not a leap year. ");

    getch();
    return 0;
}