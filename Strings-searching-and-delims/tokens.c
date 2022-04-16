#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[] = "Hello - My name is Krischal Khanal. - I am learning some programming.";
    const char delim[] = "-";
    char * token;

    // getting the first token
    token = strtok(str,delim);
    printf("The first token is %s\n",token);

    while(token != NULL)
    {
        printf("Next token = %s \n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}