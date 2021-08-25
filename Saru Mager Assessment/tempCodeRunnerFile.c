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
}

int main()
{
    struct Pradesh P[5];
    for(int i =0; i<5; i++)
    {
        printf (" Enter the name of Pradesh = ")
        gets(P[i].Name);
        printf(" Enter the Pradesh No = ");
        scanf("%d ",&P[i].No);
        printf(" Enter the name of District = ");
        gets(P[i].D.Name);
        printf(" Enter the name of Municipality = ");
        gets(P[i].D.Municipality);
        printf(" Enter the ward number = ");
        scanf("%d", &P[i].D.WardNo);
    }
    
    printf("%-30s%-s\t%-30s%-30s%s","Pradesh Name", "Pradesh No", "District Name", "Municipality", "Ward Number");
    for(int i = 0; i<5; i++)
    {
        printf("%-30s%d\t\t%-30s%-30s%d",P[i].Name, P[i].No, P[i].D.Name, P[i].D.Municipality, P[i].D.WardNo );
    }
    return 0;

}
