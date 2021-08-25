// To find HCF and LCM

#include<conio.h>
#include<stdio.h>
int main(){
    int num1,num2,a,b,c,HCF,LCM;
    printf("Enter two numbers ");
    scanf("%d %d",&num1,&num2);
    a=num1;
    b=num2;
    if(a<b)
    {
        a=num2;
        b=num1;
    }
    c=1;
    while(c!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    HCF=a;
    LCM=num1*num2/HCF;

    printf("The HCF is %d\nThe LCM is %d",HCF,LCM);
    getch();
    return 0;
}