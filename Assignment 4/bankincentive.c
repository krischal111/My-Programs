#include<stdio.h>
#include<conio.h>

int main()
{
    int balance,bonus, total;
    _Bool isFemale;
    /*
    10.	A bank has introduced an incentive policy. A bonus of 2% of the balance is given to everyone, 
    irrespective of their balances and 5% is given to female account holder if their balance is more 
    than Rs 5000/-. WAP to represent this policy and calculate balance after bonus.*/
    
    printf("Are you male (m) or female (f)");
    switch(getche())
    {
        case 'f':
        case 'F':
        isFemale = 1;
        break;
        default:
        isFemale = 0;
        break;
    }
    printf("\nEnter your balance.");
    scanf("%d",&balance);

    bonus = ( balance * 2 ) / 100;
    
    if(isFemale && balance > 5000)
    bonus = (balance * 5) / 100;

    total = balance + bonus;

    printf("Your total balance is %d",total);
    return 0;
}