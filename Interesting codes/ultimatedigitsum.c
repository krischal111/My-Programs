#include<stdio.h>
int ultimatedigitsum(int);
int main()
{
    int num, sum1,m=0,store,k,d=0;
    printf("Enter any number:\n");
    scanf("%d", &num);
    sum1=ultimatedigitsum(num);
    printf("\nThe ultimate digit sum is %d\n",sum1);
}

int ultimatedigitsum(int num)
{
    if(num<=9)
    return num;
    int sum=0;
    while(num>0)
    {
        sum+=num%10;
        num=num/10;
    }
    return ultimatedigitsum(sum);
}