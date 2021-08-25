#include<stdio.h>
#include<conio.h>

void matrixmultiply(float *, float *, float *, unsigned, unsigned, unsigned, unsigned);
int main()
{
    unsigned r1,c1, r2,c2, r3=1,c3=1;
    _Bool swapmode;         // For reverse multiply if input matrices are in wrong order

    start:
    printf("We are doing Matrix multiplicaiton.\n");
    printf("Enter the size of first matrix (row, column) = ");
    scanf("%u %u",&r1,&c1);
    
    printf("\nEnter the size of second matrix (row, column) = ");
    scanf("%u %u",&r2,&c2);

    if(c1!=r2){
        if(c2!=r1){
            printf("The matrices with the sizes you provided, cannot be multipled together.\n");
            goto start;
        }
        else
            swapmode = 1;
    }
    
    float mat1[r1][c1], mat2[r2][c2];
    if(!swapmode)
    {   r3= r1;
        c3=c2;}
    else
    {   r3= r2;
        c3=c1;
    }
    float matmult[r3][c3];

    printf("\nPlease enter the data of 1st matrix.");
    for(int i = 0; i<r1; i++){
        printf("\n");
        for(int j = 0; j<c1;j++){
            printf("Element of Row %u Column %u = ",i+1,j+1);
            scanf("%f",&mat1[i][j]);
        }
    }

    printf("\nThe value of 1st matrix is");
    for(int i = 0; i<r1; i++){
        printf("\n");
        for(int j = 0; j<c1;j++){
            printf("%.2f\t",mat1[i][j]);
        }
    }

    printf("\n\nPlease enter the data of 2nd matrix.");
    for(int i = 0; i<r2; i++){
        printf("\n");
        for(int j = 0; j<c2;j++){
            printf("Element of Row %u Column %u = ",i+1,j+1);
            scanf("%f",&mat2[i][j]);
        }
    }

    printf("\nThe value of 2nd matrix is");
    for(int i = 0; i<r2; i++){
        printf("\n");
        for(int j = 0; j<c2;j++){
            printf("%.2f\t",mat2[i][j]);
        }
    }

    if(!swapmode)
    matrixmultiply(&matmult[0][0],&mat1[0][0],&mat2[0][0],r1,c1,r2,c2);
    else
    matrixmultiply(&matmult[0][0],&mat2[0][0],&mat1[0][0],r2,c2,r1,c1);

    printf("\n\nThe result of your multiplication is");
    for(int i = 0; i<r3; i++){
        printf("\n");
        for(int j = 0; j<c3;j++){
            printf("%.2f\t",matmult[i][j]);
        }
    }

    getch();
    return 0;
}

void matrixmultiply(float * storematrix, float *firstmatrix, float *secondmatrix, unsigned r1, unsigned c1, unsigned r2, unsigned c2)
{
    if(c1==r2)
    for(int i=0; i<r1; i++)
    {
        for(int k=0; k<c2; k++)
        {
            float sum=0;
            //Debug part 1 successful I needed to skip c1 number of elements in firstmatrix, but i skipped r1
            //printf("\nAt (%d,%d) Doing addition of 0", i+1,k+1);

            //In the loop c1 can be replaced by r2
            //If c1!=r2 were the case, multiply would be invalid
            for(int j=0; j<c1; j++)
            {
                float e1 = *((firstmatrix + c1*i)+j);
                float e2 = *((secondmatrix + c2*j)+k);
                sum+=e1*e2;
                
                //Debug part 1 successful
                //printf(" + %.0f * %.0f",e1,e2);
            }
            *(storematrix+c2*i+k)=sum;
            
            //Debug part 1 successful
            //printf(" = %.0f",sum);
        }
    }
    else
    ;
}