#include<stdio.h>
void displaythematrix(float * , char , char );
float * cofactormatrix(float *, float *, char, char , char );
float * transposematrix(float * , float * , char , char );

// Works puffetly
float * transposematrix(float * outmat, float * inmat, char rows, char cols)
{
    float * output = outmat;
    for(int i = 0; i<rows; i++)
    for(int j = 0; j<cols; j++)
    *((outmat)+j*rows+i)=*((inmat)+cols*i+j); // no need to increment the addresses
    return output;
}

// Does its job
float * cofactormatrix(float *outmat, float *inmat, char size, char row, char column)
{
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

int main()
{
    float matrix1[3][2]=
    {
    {1,2},
    {3,4},
    {5,6}
    };
    float matrix2[2][3]=
    {
    {1,2,3},
    {4,5,6}
    };

    float mattrans[3][2];
    transposematrix(&matrix2[0][0],&matrix1[0][0],3,2);
    displaythematrix(&matrix2[0][0],2,3);
}