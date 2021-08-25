//Every function here works
#include<stdio.h>
float * scalarmatmult(float *, float * , float, char, char );
float * matrixmultiply(float *, float *, float *, char,char, char, char);
float * sumthematrix(float *, float *, float *, char, char);
void displaythematrix(float *, char, char);

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

    float matmult[3][2];
    scalarmatmult(&matmult[0][0],&matrix1[0][0], 5,3,2);
    displaythematrix(&matmult[0][0],3,2);
}
