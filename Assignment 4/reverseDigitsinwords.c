#include<stdio.h>

int main()
{
    int num, thisdigit = 0, temp;
    printf("Enter a number");
    scanf("%d",&num);
    temp = num;
    while(temp>0)
    {
        thisdigit=temp%10;
        temp/=10;
        switch(thisdigit)
        {
        case 0:
        printf("zero");
        break;

        case 1:
        printf("one");
        break;

        case 2:
        printf("two");
        break;

        case 3:
        printf("three");
        break;

        case 4:
        printf("four");
        break;

        case 5:
        printf("five");
        break;

        case 6:
        printf("six");
        break;

        case 7:
        printf("seven");
        break;

        case 8:
        printf("eight");
        break;

        case 9:
        printf("nine");
        break;
        }
        printf(" ");    
    }
    
}