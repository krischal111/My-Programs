// This program works

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define upperlimit 10000001
bool compositelist[upperlimit] = {0};

// function to swap two values
void intswap(int *a,int *b){    int c;    c=*a;    *a=*b;    *a=c;    }

void checkcomposites()
{
    compositelist[0]=compositelist[1]=1;
    for(int i = 2; i*i<upperlimit; i++)
    {
        if(compositelist[i]!=1)
        for(int j = i+ i; j<upperlimit; j+=i )
        {
            compositelist[j]=1;
        }
    }
}

int main(){
    int num1,num2;  // Initialization part
    bool flag;
    printf("Enter two numbers"); // Input part
 //   scanf("%d%d",&num1,&num2);
 num1=1;
 num2=100000;
    checkcomposites();

    if(num1>num2) intswap(&num1,&num2); // Exchange part
    printf("The list of prime numbers are ");
    for(int num = num1; num<=num2; num++){

        if(compositelist[num]==0)
        printf("%d ", num);
    }
    getch();
    return 0;
}

