#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[] = "Hello - My name is Krischal Khanal. - I am learning some programming.";
    const char delim[] = "-";
    char * token;

    // before getting any token
    printf("The main string = %s\n", str);

    // getting the first token
    token = strtok(str,delim);
    printf("The first token = %s\n",token);
    printf("After first tokenization,\n Main string is = %s\n", str);
    printf("\nAddress of token string = %d, \nAddress of main string  = %d\n\n",token, str);

    // further tokenization
    while(token != NULL)
    {
        printf("Next token = %s \n", token);
        printf("The address of next token = %d\n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}