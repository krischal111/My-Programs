#include<stdio.h>s
struct date
{
    // since day and month can't be aboe 30 and 12, char is sufficient as it is can store upto 256 integers
    char DD;
    char MM;
    int YYYY;
};
struct employee
{
    char name[20];
    int id;
    struct date DOB;
    float salary;
};

int main()
{
    struct employee e;
    {
        printf("Enter the name of the employee = ");
        gets(e.name);
        printf("Enter the id = ");
        scanf("%d",&e.id);
        printf("Enter the date of birth\n");
        printf("Day = ");
        scanf("%d", &e.DOB.DD);
        printf("Month = ");
        scanf("%d", &e.DOB.MM);
        printf("Year = ");
        scanf("%d", &e.DOB.YYYY);
        printf("Enter the salary = ");
        scanf("%f",&e.salary);
    }
    {
        printf("\n  Name = %s\n  ID = %d\n  Date of Birth (DD/MM/YYYY) = %d/%d/%d\n  Salary = %f",e.name,e.id, e.DOB.DD,e.DOB.MM, e.DOB.YYYY, e.salary);
    }
}