#include<stdio.h>
int main()
{
    struct studen{
        int roll;
        char name[50];
        float marks;
    }s[5];
    int i;
    for(i=0;i<5;i++)
    {
        printf("Enter the information of Student %d",i+1);
        printf("\nRoll NO. : ");
        scanf("%d",&s[i].roll);
        printf("Name : ");
        fflush(stdin);
        gets(s[i].name);
        printf("Marks : ");
        scanf("%f",&s[i].marks);
    }
    printf("\n\nThe records of student whose marks is greater than 50 are : ");
    printf("\n\nRoll NO. \t Name \t Marks");
    for(i=0;i<5;i++)
    {
        if(s[i].marks>=50)
        {
            printf("\n%d\t%s\t%f",s[i].roll,s[i].name,s[i].marks);
        }
    }
    return 0;
}