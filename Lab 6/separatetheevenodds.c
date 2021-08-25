#include<stdio.h>
#include<conio.h>


int main()
{
    unsigned int n;
    printf("Enter the number of numbers = ");
    scanf("%d",&n);
    int numbers[n], evensum=0, oddsum=0;
    printf("\nPlease enter the values now: \n");
    for(int i=1; i<=n;i++)
    {
        printf("Number %d = ",i);
        scanf("%d",&numbers[i-1]);
    }

    for(int i=0; i<n;i++)
    {
        if(numbers[i] % 2 == 0)
        evensum+=numbers[i];
        else
        oddsum+=numbers[i];
    }

    printf("The sum of even numbers is %d\nThe sum of odd numbers is %d",evensum,oddsum);

    getch();
    return 0;
}