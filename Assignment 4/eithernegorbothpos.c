#include<stdio.h>

int main()
{
    int a,b,c,d;
    printf("Enter two numbers. ");
    scanf("%d %d",&a,&b);
    if(a<0 || b<0)
    goto eitherneg;
    else
    goto bothpos;
    eitherneg:
    printf("Either of the number is negative. ");
    goto end;
    bothpos:
    printf("Both of the numbers are positive. ");
    end:
    return 0;
}