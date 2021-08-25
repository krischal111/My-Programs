#include<stdio.h>

int main()
{
    int size = 10;
    int marks[size];
    for(int i = 0; i < size; i++)
    {
        printf("Enter the marks of student %d = ",i);
        scanf("%d",marks+i);
    }
    
    for(int i = 0; i < size; i++)
    {
        printf("Mark of student %d = %d\n",i,*(marks+i));
    }
    return 0;
}