#include<stdio.h>
#include<string.h>
#include<conio.h>

void modprint(char * text, int , int, int);

int main()
{
    char inputtext[20] = "KNOWPROGRAM";
    int n = 10;

    printf("Enter any text and number of lines = ");
    scanf("%s %d", inputtext, &n);

    for(int i = 0; i<n; i++)
    {
        printf("\n%*s",n-i,"");
        modprint(inputtext, strlen(inputtext), (i*(i+1))/2 , i+1);
    }
    getch();
}

void modprint(char *text, int size, int start, int numofletters)
{
    while(start>=size){start-=size;}
    int n = (numofletters <= (size-start))?numofletters:(size-start);

    for(int i =0; i<n; i++)
    printf("%c ",*(text+start+i));

    if(numofletters+start<=size)
    return;
    else
    modprint(text, size, 0, numofletters - n);
}