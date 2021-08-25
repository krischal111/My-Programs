/*WAP to define three user defined function for reading, processing and displaying of 2*3 matrices. 
Double the matrix element and display it.*/

#include<stdio.h>
void inputthematrix(float *, char, char);
void displaythematrix(float *, char, char);
float *scalarmatmult(float *, float *, float, char, char);

int main()
{
    const int rows = 2, cols = 3;
    float M[rows][cols];
    float DoubledM[rows][cols];

    printf("Enter the elements of 2x3 matrix please:");     //Input
    inputthematrix(M[0],rows,cols);
    
    scalarmatmult(DoubledM[0],M[0],2,rows,cols);            //Process
    
    printf("\nThe Doubled Matrix is:");                     //Output
    displaythematrix(DoubledM[0],rows, cols);
    return 0;
}



void inputthematrix(float * inmat, char rows, char cols)
{
    for(char i=0; i<rows; i++)
    {
        printf("\n");
        for(char j = 0; j<cols; j++)
        {
            printf("Enter the element of %dth row and %dth column = ",i+1,j+1);
            scanf("%f",(inmat++));
        }
    }
}

void displaythematrix(float * inmat, char rows, char cols)
{
    for(char i=0; i<rows; i++)
    {
        printf("\n");
        for(char j = 0; j<cols; j++)
        printf("%.2f\t",*(inmat++));
    }
}

float * scalarmatmult(float * outmat, float * inmat, float mult, char rows, char cols)
{
    float * output = outmat;
    for(int i=0; i < rows; i++)
    for(int j=0; j < cols; j++)
    {
        *(outmat++) = *(inmat++)*mult;
    }
    return output;
}

