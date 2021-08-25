#include<stdio.h>

 struct empr
{
    char name[30];
    int age;
    int salary;
};


int main()
{
    struct empr e[100];
    int end = 0, count = 0;
    char ans = 'y';

    // Data retrieval phase, uses fread
    FILE * myfile = fopen("Employee.txt","rb");
    for(int i = 0; (i<100 && fread( &e[i], sizeof(struct empr), 1, myfile) != EOF && myfile != NULL); i++)
    {
        count++;
    }
    fclose(myfile);

    for(int i = count; ((i<100)); i++)
    {
        fflush(stdin);
        printf("Do you want to add more data (y/n)? ");
        ans = getchar();
        if(ans == 'n' || ans == 'N')
        break;

        printf("Enter name: ");
        fflush(stdin);
        gets(e[i].name);
        printf("Enter age and salary = ");
        scanf("%d %d", &e[i].age, &e[i].salary);
        count++;
    }

    myfile = fopen("Employee.txt","wb");
    for(int i = 0; i<count; i++)
    {
        fwrite(&e[i],sizeof(struct empr),1,myfile);
    }
    fclose(myfile);
    

    // Data printing phase
    printf("The total stored data are:\n%-30s\t%s\t%10s","Name","Age","Salary");

    for(int i = 0; i<count; i++)
    {
        printf("\n%-30s\t%d\t%10d",e[i].name,e[i].age,e[i].salary);
    }

    return 0;
}