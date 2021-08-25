// Checking prime numbers in a range

#include<stdio.h>
#include<conio.h>

void intswap(int *,int *);

int main()
{
    unsigned int num1, num2;
    printf("Enter two numbers = ");
    scanf("%d %d",&num1,&num2);
    
    if(num1>num2)
    intswap(&num1,&num2);           // Making num2 a larger number
    
    _Bool compositelist[1000000];    // Generating all list of composite numbers upto upperlimit
    compositelist[0] = 1;
    compositelist[1] = 1;
    for(int i = 2; i*i<num2 ; i++)
    {
        if(compositelist[i]!=1)
        for(int j = i+ i; j<=num2; j+=i )
        {
            compositelist[j]=1;
        }
    }

    for(int i = num1; i<=num2; i++)
    {
        if(!compositelist[i])
        printf("%d, ",i);
    }

}

void intswap(int *a,int *b){    int c;    c=*a;    *a=*b;    *a=c;    }