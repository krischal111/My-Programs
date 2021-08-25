/*WAP to search an element in an array and display the index of it*/

#include<stdio.h>
int numlist[10] = {1,2,3,4,5,10,9,8,7,6};
int main()
{
    int a, index=-1;
    printf("Emter a number please (1 - 10): ");
    scanf("%d",&a);
    for(int i = 0; i<10; i++)
    {
        if(a == numlist[i])
        {
            index = i;
            break;
        }
    }
    if(index==-1)
    {
        printf("Your number doesn't exist on the list.");
        return 0;
    }

    printf("The index of your number is %d",index);
    return 0;
}