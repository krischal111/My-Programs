#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
float factorial(int);

int main()
{
    float ang,rangedangle,sine=0;
    int n;
    printf("Enter the value of angle (radians) = ");
    scanf("%f",&ang);
    printf("Enter the number of terms = ");
    scanf("%d",&n);

    rangedangle = ang - ((int)(ang/(2 * PI))) * (2 * PI) ; // Fancy way of finding remainder when divided by 2 PI

    for(int i = 1; i<=n ; i++)
    {
        
        sine+= pow(rangedangle,(2*i - 1)) / factorial(2* i -1) * ((i&1==1)?1:-1);
    }

    printf("The answer is  sin (%f)  = %.2f ",ang, sine);
    return 0;    
}

float factorial(int i)
{
    if(i==0)
        return 1;
    else if(i>0)
        return i*factorial(i-1);
    else
    return (-1);
}