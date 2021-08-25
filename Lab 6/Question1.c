/*
WAP to read the order of two matrices from the user . 
Read elements of the matrices using function and then find product of matrices . 
Finally , display the resultant matrix using another function.
*/

#include<stdio.h>
void inputthematrix(float *, char , char);
float * matmult(float *, float *, float *, char, char, char, char);
void displaythematrix(float *, char, char);

int main()
{
    int a,b,c,d,e,f;
    printf("Enter the rows and the column of the matrices\n For first matrix: ");
    scanf("%d%d",&a,&b);
    printf("For second matrix : ");
    scanf("%d%d",&c,&d);
    
    int mode = (b==c)?1:((a==d)?-1:0);

    if(mode == 0)
    {
        printf("The matrices with rows and columns you provided cannot be multiplied to each other.");
        return -1;
    }
    else if(mode == 1)
    {
        e = a;
        f = d;
    }
    else
    {
        e = c;
        f = b;
    }

    float M1[a][b];
    float M2[c][d];
    float MMult[e][f];
    printf("Enter the data of first matrix.");
    inputthematrix(M1[0],a,b);
    printf("\nEnter the data of the second matrix.");
    inputthematrix(M2[0],c,d);


    if(mode == 1)
    matmult(MMult[0],M1[0],M2[0],a,b,c,d);
    else
    matmult(MMult[0],M2[0], M1[0],c,d,a,b);

    displaythematrix(MMult[0],e,f);
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

float * matmult(float * outmat, float * inmat1, float * inmat2, char a, char b, char c, char d)
{
    if(b!=c)
    return NULL;

    for(int i = 0; i<a; i++)
    for(int j = 0; j<d; j++)
    {
        float sum = 0;
        for(int k = 0; k<b; k++) // since b==c, condition can also be k<c
        {
            sum+= (inmat1[i*b+k]) * (inmat2[k*d+j]);
        }
        outmat[i*a+j] = sum;
    }

    return outmat;
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

