#include<stdio.h>

int main()
{
    FILE * myfile = fopen("test2.c","r");
    if(myfile==NULL)
    return -1;
    char c=fgetc(myfile);
    while(c!=EOF)
    {
        putchar(c);
        c=fgetc(myfile);
    }
    return 0;
    
}