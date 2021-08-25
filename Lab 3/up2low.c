// Change a character from upper to lower or lower to upper.

#include<stdio.h>
#include<conio.h>
#include<string.h>

char ch, convert_text[10]="UPPERCASE";
char main()
{
    printf("Enter a character: ");
    scanf(" %c",&ch);

    if(64<ch&&ch<=90)
    {
        ch+=(char)32;
        strcpy(convert_text,"lowercase");
    }
    else if(96<ch&&ch<=122)
    {
        ch-=(char)32;
        
    }

    printf("Your character into %s is %c",convert_text,ch);

    getch();
    return ch;
}
