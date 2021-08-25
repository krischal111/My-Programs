#include<stdio.h>
#include<conio.h>

int main()
{
    int n,r;
    printf("Enter the value of n and r");
    scanf("%d %d",&n,&r);
    
    long nfac=1;
    for(int i = 1; i<=n; i++)
    {
        nfac*=i;
    }

    long rfac=1;
    for(int i = 1; i<=r; i++)
    {
        rfac*=i;
    }

    long nrfac=1;
    for(int i = 1; i<=n-r; i++)
    {
        nrfac*=i;
    }

    long nCr = (nfac/(rfac*nrfac));

    printf("The nCr is %d", nCr);
}