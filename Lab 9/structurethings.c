#include<stdio.h>

struct Student
{
    char name[20];
    int age;
    float marks;
} s;

int main()
{
    const int size = 5;
    struct Student members[size];
    printf("\nEnter the data of %d students:\n",size);
    for(int i = 0; i< size; i++)
    {
        printf("\nFor student %d\nEnter name = ",i+1);  scanf("%19s",members[i].name);
        printf("Enter age = ");                         scanf("%d",&members[i].age);
        printf("Enter marks = ");                       scanf("%f",&members[i].marks);
    }

    printf("\n The data endered were as follows:");

    for(int i = 0; i< size; i++)
    {
        printf("\nFor student %d\nName = %s ",i+1,members[i].name);
        printf("\nAge = %d",members[i].age);
        printf("\nMarks = %.2f\n",members[i].marks);
    }

   return 0;

}