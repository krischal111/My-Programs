#include<stdio.h>

int main()
{
    int n1,n2,count=0;
    printf("Enter two numbers. ");
    scanf("%d %d",&n1,&n2);
    for(int i = n1; i<=n2; i++)
    {
        if(i%7!=0)
        continue;
        count++;
    }
    printf("The number of digits divisible by seven between %d and %d is %d.",n1,n2,count);
    return 0;
}