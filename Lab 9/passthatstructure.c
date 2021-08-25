#include<stdio.h>

struct student
{
    char name[20];
    int age;
    int marks;
} s;

void display(struct student s)
{
    printf("Name\t\tAge\tMarks");
    printf("\n%s\t%d\t%d",s.name,s.age,s.marks);
    return;
}
int main()
{
    strcpy(s.name, "Krischal Khanal");
    s.age = 20;
    s.marks = 100;
    display(s);
}