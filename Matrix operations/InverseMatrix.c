#include<stdio.h>
void displaythematrix(float * , char , char );
float * cofactormatrix(float *, float *, char, char , char );
float determinantof(float *, unsigned char, unsigned char);
float * actualcofactormatrix(float *, float * , char);
float * transposematrix(float * , float * , char , char );
float * scalarmatmult(float *, float * , float, char, char );
int inversematrix(float *, float *, unsigned char);
int main()
{
    float matrix1[3][3]=
    {
    {1,2,3},
    {3,4,5},
    {5,6,9}
    };
    
    float Inversematrix1[3][3];
    int singular = inversematrix(&Inversematrix1[0][0],&matrix1[0][0],3);
    
    if(!singular)
    {
        printf("The inverse matrix is");
        displaythematrix(&Inversematrix1[0][0],3,3);
    }
    else
    printf("The matrix is singular");
    
}

int inversematrix(float * outmat, float * inmat, unsigned char size)
{
    float det = determinantof(inmat,size,0);
    if(det==0)
        return -1;
    else
    {
        float cofactormat[size][size];
        actualcofactormatrix(&cofactormat[0][0],inmat,size);
        float adjoint[size][size];
        transposematrix(&adjoint[0][0],&cofactormat[0][0],size,size);
        scalarmatmult(outmat,&adjoint[0][0],(1/det),size,size);
        return 0;
    }
}


// worked previously so yeah, it works.
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

// creates a matrix from which cofactor can be calculated
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

// creates a matrix of all cofactors
float * actualcofactormatrix(float * outmat, float * inmat, char size)
{
    float * output = outmat;
    float * nothing;        // since we are using function that return memory address
    float submatrix[size-1][size-1];
    for(int i = 0; i<size; i++)
    for(int j = 0; j<size; j++)
    {
        _Bool sign = ((i+j)%2==0);
        
        nothing = cofactormatrix(&submatrix[0][0],inmat,size ,i+1,j+1);   // mathematically consistent counting there
        *(outmat++) = determinantof(&submatrix[0][0],size-1,1) * (sign?1:-1);
    }
    return output;
}

// Displays the matrix
void displaythematrix(float * inmat, char rows, char cols)
{
    for(char i=0; i<rows; i++)
    {
        printf("\n");
        for(char j = 0; j<cols; j++)
        printf("%-10.5f",*(inmat++));
    }
}

// Transposes the matrix
float * transposematrix(float * outmat, float * inmat, char rows, char cols)
{
    float * output = outmat;
    for(int i = 0; i<rows; i++)
    for(int j = 0; j<cols; j++)
    *((outmat)+j*rows+i)=*((inmat)+cols*i+j); // no need to increment the addresses
    return output;
}

//Multiplies a matrix with a float value
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
