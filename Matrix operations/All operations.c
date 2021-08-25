#include<stdio.h>

void inputthematrix(float *, char, char);
void displaythematrix(float *, char, char);
float * scalarmatmult(float *, float * , float, char, char );
float * matrixmultiply(float *, float *, float *, char,char, char, char);
float * sumthematrix(float *, float *, float *, char, char);
float * cofactormatrix(float *, float *, char, char , char );
float determinantof(float *, unsigned char, unsigned char);
float * actualcofactormatrix(float *, float * , char);
float * transposematrix(float * , float * , char , char );
int inversematrix(float *, float *, unsigned char);

int main()
{
    int rows, cols;
    
    printf("Enter the rows and columns of the matrix. ");
    scanf("%d %d",&rows, &cols);

    float Matrix[rows][cols];
    inputthematrix(&Matrix[0][0],rows, cols);

    float Transpose[cols][rows];
    float Matrixproduct1[rows][rows];
    float Matrixproduct2[cols][cols];
    printf("\nThe given matrix is:");
    displaythematrix(&Matrix[0][0],rows, cols);
    printf("\n\nThe transpose of the given matrix is:");
    displaythematrix(transposematrix(&Transpose[0][0],&Matrix[0][0],rows,cols),cols,rows);
    printf("\n\nThe multiplication of the matrix with its own transpose is:");
    displaythematrix(matrixmultiply(&Matrixproduct1[0][0],&Matrix[0][0],&Transpose[0][0],rows,cols,cols,rows),rows, rows);
    printf("\n\nThe multiplication of Transpose of the matrix with the matrix is:");
    displaythematrix(matrixmultiply(&Matrixproduct1[0][0],&Transpose[0][0],&Matrix[0][0],cols,rows,rows,cols),cols, cols);

    if(rows == cols)
    {
        float determinant = determinantof(&Matrix[0][0],rows,0);
        printf("\n\nSince the matrix is a square matrix \nThe determinant of the matrix is %.2f",determinant);
        float Inversematrix[rows][cols];
        int singular = inversematrix(&Inversematrix[0][0],&Matrix[0][0],3);
        if(!singular)
        {
            printf("\n\nThe inverse matrix is");
            displaythematrix(&Inversematrix[0][0],3,3);
        }
        else
        printf("\nThe matrix is singular so it doesn't have an inverse");
    }
    else
    printf("Since the matrix is a rectangular matrix, it doesn't have a determinant or an inverse.");
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


//works like a charm
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

//Works flawlessly
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

//Works flawlessly
float * sumthematrix(float * outmat, float * inmat1, float * inmat2, char rows, char cols)
{
    float * output = outmat;
    for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    *(outmat++)=*(inmat1++)+*(inmat2++);
    return output;
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