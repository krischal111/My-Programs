#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Please enter an string = ");
    fgets(str, 100, stdin);
    int len = strlen(str);

    for(int i = len-1; i>=0; --i)
        putchar((str[i]));

        return 0;
}