/*WAP to read the order of a square matrix and its elements from the keyboard. 
Find the sum of diagonal elements of the matrix.*/

#include<stdio.h>
void inputthematrix(float *, char, char);
void displaythematrix(float *, char, char);
float diagonalsum(float *, char);

int main()
{
    unsigned char n;                                // Creation of the Matrix
    printf("Enter the size of square matrix = ");
    scanf("%u",&n);
    float M[n][n];

    inputthematrix(M[0],n,n);                       // Input
    printf("\nYour matrix was:");
    displaythematrix(M[0],n,n);
    
                                                    // Process and the Output
    printf("\n\nSum of diagonal elements is: %.2f",diagonalsum(M[0],n));
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

float diagonalsum(float * inmat, char size)
{
    float sum=0;
    for(char i=0; i<size; i++)
    {
        sum+=*(inmat++);
        inmat+=size;
    }
    return sum;
}