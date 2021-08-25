#include<stdio.h>
void displaythematrix(float * , char , char );
float * cofactormatrix(float *, float *, char , char , char );
float determinantof(float *, unsigned char , unsigned char );

// Works for square matrices only
float * cofactormatrix(float *outmat, float *inmat, char size, char row, char column)
{                                           // rows and column counting starts from 1, math convention
    float *output=outmat;
    row--; column--;                        // During implementation, however, we use programmer's convention
    for(int i=0; i<size; i++)               // i is the row of matrix
    {
        if(i==row)                          // We move to another row
        {inmat+=size;continue;}             // plus we skip assigning for this iteration
        for(int j = 0; j<size; j++)         // j is the column of matrix
        {
            if(j==column)                   // We move to another column
            {inmat++;continue;}             // plus we skip assigning for this iteration
            *(outmat++) = *(inmat++);       // First assign then increment
        }
    }
    return output;
}

// Also works
float determinantof(float *inmat, unsigned char size, unsigned char depth)
{
    float * nothing; // Since we are using functions that return memory address
    if(size==0)
    return 1;
    if(size==1)
    return * inmat;

    float submat[size-1][size-1];
    float det=0;

    for(int i = 0; i<size; i++)
    {
        _Bool sign = (i%2==0);          // True if even
        nothing = cofactormatrix(&submat[0][0],inmat,size,1,i+1);    // Count starting from 0 for matrix position
        float cofactor = (sign?1:-1)*determinantof(&submat[0][0],size-1,depth+1);
        det += (*(inmat+i))*cofactor;
    }
    return det;
}

// Already works
void displaythematrix(float * inmat, char rows, char cols)
{
    for(char i=0; i<rows; i++)
    {
        printf("\n");
        for(char j = 0; j<cols; j++)
        printf("%.2f\t",*(inmat++));
    }
}

int main()
{
    float matrix1[3][3]=
    {
    {1,2,3},
    {3,4,5},
    {5,6,6}
    };

    float matrix2[2][3]=
    {
    {1,2,3},
    {4,5,6}
    };

    //float matmult[3][2];
    //scalarmatmult(&matmult[0][0],&matrix1[0][0], 5,3,2);
    printf("Determinant = %f",determinantof(&matrix1[0][0],3,0));

    //displaythematrix(&matmult[0][0],3,2);
}
