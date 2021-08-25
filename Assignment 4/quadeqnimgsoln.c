//quad equation solution

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    float a,b,c,dis, p1, p2, x1, x2;
    char ch;
    beginning:
    printf("\nEnter a quadratic equation.(Just enter the three coefficients) \n");
    scanf("%f%f%f",&a,&b,&c);
    printf("Your question was %.2fx\xfd + %.2fx+ %.2f = 0 \n",a,b,c);
    
    if(a!=0)
    {
        dis = (b*b-4*a*c);
        p1 = -b/(2*a);
    
        if(dis>=0)
            p2=sqrt(dis)/(2*a);
        else
            p2=sqrt(-dis)/(2*a);
        
        if(dis>=0)
        {
            x1 = p1+p2;
            x2 = p1-p2;
            printf("The roots are real and they are\n    x1 = %.2f \n    x2 = %.2f.",x1,x2);
        }
        else
        {
            printf("The roots are complex and they are\n    x1 = %.2f + %.2f i \n    x2 = %.2f - %.2f i",p1,p2,p1,p2);
        }
    }
    else printf("Value of first coefficient cannot be zero.");

    getch();
    
    //optional part
    {
    while(getchar()!='\n') ; // Just clearing remaining previously pressed enter key
    printf("\n\n Do you want to start again (press y if yes, enter key if no)");// Asking if start again.
    ch=getchar();
    if(ch=='y'||ch=='Y')
        goto beginning;
    }
    return 0;  
}
