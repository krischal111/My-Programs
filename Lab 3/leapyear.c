//Leap year program

#include<stdio.h>
#include<conio.h>

int main(){
    int year;

    printf("Enter the year in AD ");
    scanf("%d",&year);

    if(year%400==0)
        printf("The year is a leap year");
    else if(year%100==0)
        printf("The year is not a leap year");
    else if(year%4==0)
        printf("The year is a leap year");
    else
        printf("The year is not a leap year");

    getch();
    return 0;
}
