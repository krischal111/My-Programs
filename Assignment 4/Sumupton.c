#include<stdio.h>
#include<conio.h>
 
int main(){
    int sum,a;
    sum=0;
    printf("Enter a number = ");
    scanf("%d",&a);
    int i =0;
    while(i++<a)
    {
        sum+=i;
    }
    if(a=0) sum=1;

    if(a<0)
    printf("Please enter the positve number.");
    else
    printf("Your factorial was %d",sum);

    getch();
    return 0;
}

    
    