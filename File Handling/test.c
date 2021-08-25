/*
WAP to create a file named “test.txt” and write text” welcome to my college” to this file.
*/

#include<stdio.h>

int main()
{
    FILE * fptr = fopen("Test.txt","w");
    fputs("welcome to my college",fptr);
    return 0;
}