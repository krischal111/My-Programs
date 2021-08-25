//  Celcius to fahrenheit

#include<stdio.h>
float fahrenheitof(float);

int main()
{
    float cel;
    printf("Enter a temperature in celcius. ");
    scanf("%f",&cel);
    printf("The temperature in Fahrenheit is %.2f",fahrenheitof(cel));
}

float fahrenheitof(float cel) 
{     return cel*1.8-32;  }