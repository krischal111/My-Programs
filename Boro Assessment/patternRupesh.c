// Pattern

#include<stdio.h>
#include<conio.h>

int main()
{
    char name[30];
    printf("Enter your first name. ");
    scanf(" %29s",name);
    for(int i = 0;i<30; i++)
    {
        if(name[i]==0)
        break;          // when last character is reached

        for(int j = 0; i<=i; j++)   // Loops to display characters upto i
        printf("%c",name[j]);

        printf("\n");
    }

    getch();
    return 0;
}