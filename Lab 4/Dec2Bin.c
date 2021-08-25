// To convert binary into decimal

#include<stdio.h>

int main()
{
    int dec;
    printf("Enter a number = ");
    scanf("%d",&dec);
    
    int temp = dec, numdigbin=0;
    while(temp>0)
    {
        temp = temp>>1;     // Divide by 2, drop last digit
        numdigbin++;        // Count number of binary digits
    }

    temp = dec;
    do
    {
        printf("%d",1&(temp>>--numdigbin)); // Display the (numdigbin) th digit, i.e. first digit of binary number
    }while(numdigbin>0);
}