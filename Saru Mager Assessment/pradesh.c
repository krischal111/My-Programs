// Pradesh Question

#include<stdio.h>

struct District 
{
    char  Name[30];
    char  Municipality[30];
    int WardNo;
};

struct Pradesh
{
    char Name[30];
    int No;
    struct District D;
};

int main()
{
    struct Pradesh P[5];
    for(int i =0; i<5; i++)
    {
        printf (" Enter the name of Pradesh = ");
        fflush(stdin);
        gets(P[i].Name);
        printf(" Enter the Pradesh No = ");
        scanf("%d",&P[i].No);
        printf(" Enter the name of District = ");
        fflush(stdin);
        gets(P[i].D.Name);
        printf(" Enter the name of Municipality = ");
        fflush(stdin);
        gets(P[i].D.Municipality);
        printf(" Enter the ward number = ");
        scanf("%d", &P[i].D.WardNo);
    }

    printf("\n%-30s%s\t%-30s%-30s%s","Pradesh Name", "Pradesh No", "District Name", "Municipality", "Ward Number");
    for(int i = 0; i<5; i++)
    {
        printf("\n%-30s%2d\t\t%-30s%-30s%d",P[i].Name, P[i].No, P[i].D.Name, P[i].D.Municipality, P[i].D.WardNo );
    }
    return 0;

}
