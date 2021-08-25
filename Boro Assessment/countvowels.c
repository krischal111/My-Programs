// Count vowels in name

#include<stdio.h>
#include<conio.h>

int main()
{
    char name[30];
    int countvowels=0;
    printf("Enter your full name.");
    scanf(" %29s",name);

    for(int i = 0; i< 30; i++)
    {
    int breakmode=0;
    switch(name[i])
    {
        case '\0':
        breakmode = 1;
        break;  // break when last character (always null in string)
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        countvowels++;
        break;
    }
    
    if (breakmode = 1) // only true when last character is reached
    break;
    }

    printf("The number of vowels in your name is %s");
    getch();
    return 0;
}