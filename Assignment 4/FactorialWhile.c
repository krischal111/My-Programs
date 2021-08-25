#include<stdio.h>
#include<conio.h>
 
int main(){
    int f,a;
    f=1;
    printf("Enter a number = ");
    scanf("%d",&a);
    int i =0;
    while(i++<a)
    {
        f*=i;
    }
    if(a=0) f=1;

    if(a<0)
    printf("Please enter the positve number.");
    else
    printf("Your factorial was %d",f);

    getch();
    return 0;
}

    
    