#include<stdio.h>
#include<conio.h>

void sortthem(int *, int, char);
void intswap(int *, int *);

int main()
{
    unsigned int n;
    printf("\n       ***Sorting program***\nEnter the number of numbers = ");
    scanf("%d",&n);
    int numbers[n];
    printf("\nPlease enter the values now: \n");
    for(int i=0; i<n;i++)
    {
        printf("Number %d = ",i+1);
        scanf("%d",&numbers[i]);
    }

    char mode = 'a'; // ascending mode
    sortthem(&numbers[0], n, mode);
    
    printf("\nThe values sorted are: \n");
    for(int i=0; i<n; i++)
    {
        printf("Number %d = %d\n",i+1, numbers[i]);
    }

    getch();
    return 0;
}

void sortthem(int * numbers, int n,char mode)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if (mode == 'a')
            {
                if(numbers[i] > numbers[j])
                intswap(&numbers[i] , &numbers[j]);
            }
            else if (mode == 'd')
            {
                if(numbers[i] < numbers[j])
                intswap(&numbers[i] , &numbers[j]);
            }
        }
    }
    return;
}

void intswap(int * a , int * b ){int c = *a; *a = *b; *b = c;}