#include<stdio.h>
int main()
{
    float x,y;
    //y={2x+300 for x<50, 200 for x=50 and 50x-100 for x>50}.

    printf("Enter the value of x = "   );
    scanf("%d",&x);

    if(x<50)
    y= 2*x + 300;
    else if(x ==50)
    y = 200;
    else if(x>50)
    y = 50*x-100;

    printf("The value of y is %d",y);
    return 0;

}