// WAP to read a number from the keyboard until a zero 
// or a negative number is keyed in . 
//Finally calculate sum and average of entered numbers.

#include<conio.h>
#include<stdio.h>

int main()
{
    int a,i=0,sum=0;
    float avg;
    printf("Enter a number, enter negative number to exit. \n");
    do{
        scanf("%d",&a);
        
        sum +=a;
        i++;

    } while(a>0);
    
    avg = (sum)/((float)i);
    printf("The average of your entered numbers was %f. And sum is %d",avg,sum);

    getch();
    return 0;
}
/*10
20
15
5
0
*/