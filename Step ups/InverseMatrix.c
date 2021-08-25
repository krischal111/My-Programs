#include<stdio.h>



// Takes a matrix, its size, and position of a element in it
// Returns a cofactor matrix corresponding to that element, cofactor here means the matrix where cofactor comes from
// For compatibility with math conventions, row and column counting starts from 1
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

// Works perfectly
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

float * transposematrix(float * outmat, float * inmat, char rows, char cols)
{
    float * output = outmat;
    for(int i = 0; i<rows; i++)
    for(int j = 0; j<cols; j++)
    *((outmat++)+j*rows+i)=*((inmat++)+cols*i+j);
    return output;
}

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
        *((outmat++)+size*i+j) = determinantof(&submatrix[0][0],size-1,1) * (sign?1:-1);
    }
    return output;
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

float * matrixmultiply(float * outmat, float * inmat1, float * inmat2, char r1,char c1, char r2, char c2 )
{
    float * output = outmat;
    for(int i=0; i<r1; i++)
    {
        for(int k=0; k <c2; k++)
        {
            float sum=0;
            for(int j=0; j <c1;j++)
            {
                float e1 = *(inmat1+i*c1+j);
                float e2 = *(inmat2+j*c2+k);
                sum+=e1*e2;
            }
            *(outmat++)=sum;
        }
    }
    return output;
}

float * matrixsum(float * outmat, float * inmat1, float * inmat2, char rows, char cols)
{
    float * output = outmat;
    for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    *(outmat++)=*(inmat1++)+*(inmat2++);
    return output;
}



int main()
{
    float * nothing;        // since we are using function that return memory address
    char size=3;
    float matrix[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    float comatrix[size][size];
    float transmat[size][size];
    float det = determinantof(&matrix[0][0], 3, 0);

    nothing = actualcofactormatrix(&comatrix[0][0],&matrix[0][0],3);

    nothing = transposematrix(&transmat[0][0],&comatrix[0][0],size,size);
    
    printf("Determinant is %.0f",det);

    for(int i=0; i<size; i++)
    {
    printf("\n");
    for(int j=0; j<size; j++)
    printf("%.0f ",comatrix[i][j]);
    }

    for(int i=0; i<size; i++)
    {
    printf("\n");
    for(int j=0; j<size; j++)
    printf("%.0f ",transmat[i][j]);
    }

    while(getchar()!='\n');
}