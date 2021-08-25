#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long int fnum,pnum,mpower = 0, fact =1;
    scanf("%ld %ld",&fnum,&pnum);
    if(1> fnum || 25 < fnum )
        return 0;
    for(int i =1; i<=fnum; i++)
        fact *=i;
    while(fact >= 0 && fact % pnum == 0 )
    {
        fact/=pnum;
        mpower++;
    }
    printf("%ld",mpower);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
