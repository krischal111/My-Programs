// Matrix Question

#include<stdio.h>

int main()
{
    unsigned int M;
    printf("Enter the row of matrix = ");
    scanf("%u",&M);

    int Mat[M][M];

    for(int i = 0; i<M; i++)
    {
        printf("\n");
        for(int j = 0; j<M; j++)
        {
            printf("Enter the %d, %d element = ", i+1, j+1);
            scanf("%d",&Mat[i][j]);
        }
    }

    for (int i = 0; i<M; i++)
    Mat[M-i-1][i]*=12;

    for(int i=0; i<M; i++)
    Mat[i][i]+=14;

    for(int i = 0; i<M; i++)
    {
        printf("\n");
        for(int j = 0; j<M; j++)
        {
            printf("%d\t",Mat[i][j]);
        }
    }

}