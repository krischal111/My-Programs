// LCR question

#include<stdio.h>
#include<math.h>
float CalculateFrequency(float, float, float);


int main()
{
    float L,C,R, f;
    printf("Enter the values of L, C and R = ");
    scanf("%f %f %f", &L, &C, &R);

    int i=1;
    printf("%s\t%s\t%s\tFrequency","L","C","R");
    printf("\n%.2f\t%.2f\t%.2f\t%.2f",L,C,R,CalculateFrequency(L,C,R));
    while(i<10)
    {
        printf("\n%.2f\t%.2f\t%.2f\t%.2f",L,0.1*i,R,CalculateFrequency(L,0.1*i,R));
        i++;
    }
    return 0;

}

float CalculateFrequency(float L, float C, float R)
{
    ;
    return sqrt( (1/(L*R) -(R/(4*C) ) ) );
}


