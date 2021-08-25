#include<stdio.h>

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        printf("\n");
        for(int j = 5; j <= 10; j++)
        printf("%d x %d = %d \t",j,i,j*i);
    }
}