#include<stdio.h>

void inputthematrix(float *, char, char);
void displaythematrix(float *, char, char);

int main()
{
    int rows, cols;
    
    printf("Enter the rows and columns of the matrix. ");
    scanf("%d %d",&rows, &cols);

    float Matrix[rows][cols];
    inputthematrix(&Matrix[0][0],rows, cols);
    displaythematrix(&Matrix[0][0],rows, cols);
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

// Works
void displaythematrix(float * inmat, char rows, char cols)
{
    for(char i=0; i<rows; i++)
    {
        printf("\n");
        for(char j = 0; j<cols; j++)
        printf("%.2f\t",*(inmat++));
    }
}