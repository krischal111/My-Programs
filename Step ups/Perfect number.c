#include<stdio.h>
#include<conio.h>

int main()
{
    int num, factorsum;
    printf("Enter a number = ");
    scanf("%d",&num);
    factorsum=0;
    for(int i = 1; i<= num/2; i++)
    {
        if(num%i==0) factorsum+=i;
    }
    printf("Your number %s a Perfect number.",((factorsum==num)?"is":"is not"));
    getch();
    return 0;

}