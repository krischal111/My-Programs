#include<stdio.h>

struct employee
{
    char name[20];
    int id;
    float salary;
} emp;

void display(struct employee e)
{
    printf("Name\t\tID\tSalary");
    printf("\n%s\t%d\t$%.2f",e.name,e.id,e.salary);
    return;
}

void increase(struct employee *e)
{
    e->salary+=2000;
}

int main()
{
    strcpy(emp.name, "Krischal Khanal");
    emp.id = 111;
    emp.salary = 100000;
    printf("\nBefore increasing\n");
    display(emp);
    increase(&emp);
    printf("\nAfter increasing \n");
    display(emp);
}