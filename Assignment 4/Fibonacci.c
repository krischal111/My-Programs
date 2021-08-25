// To generate fibonacci series using n1, and n2 upto n numbers, where n1 = 0, n2 = 1 and n is the user input.

#include<conio.h>
#include<stdio.h>
int main(){
    int a,b,n;
    a=0;
    b=1;
    printf("Enter the number of terms to generate = ");
    scanf("%d",&n);
    int series[n];
    series[0]=a;
    series[1]=b;
    for(int i = 2; i<n; i++)
    {
	    series[i]=series[i-2]+series[i-1];
    }
    printf("The fibonacci series is \n");
    for(int i = 0; i<n; i++)
    {
	    printf("%-6d",series[i]);
    }
    getch();
    return 0;
}