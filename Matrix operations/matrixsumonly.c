#include<stdio.h>
void inputthematrix(float *, char, char);
void displaythematrix(float *, char, char);
float * sumthematrix(float *, float *, float *, char, char);

int main()
{
    int rows, cols;
    
    printf("Enter the rows and columns of the matrix. ");
    scanf("%d %d",&rows, &cols);

    float Matrix1[rows][cols];
    float Matrix2[rows][cols];
    float Matrix3[rows][cols];
    printf("\nEnter the value of Matrix 1:");
    inputthematrix(&Matrix1[0][0],rows, cols);
    printf("\nEnter the value of Matrix 2");
    inputthematrix(&Matrix2[0][0],rows, cols);
    sumthematrix(Matrix3[0],Matrix2[0],Matrix1[0],rows,cols);
    printf("\nThe sum is:");
    displaythematrix(&Matrix3[0][0],rows, cols);
}

// works
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

//Works flawlessly
void displaythematrix(float * inmat, char rows, char cols)
{
    for(char i=0; i<rows; i++)
    {
        printf("\n");
        for(char j = 0; j<cols; j++)
        printf("%.2f\t",*(inmat++));
    }
}

//Works flawlessly
float * sumthematrix(float * outmat, float * inmat1, float * inmat2, char rows, char cols)
{
    float * output = outmat;
    for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    *(outmat++)=*(inmat1++)+*(inmat2++);
    return output;
}