#include <stdio.h>
#include <string.h>
void sortstring(char str[][64], int);
void display(char str[][64], int n);

int main()
{
    char string[][64] = 
    {
        "This is the first string.",
        "Another string.",
        "A quick brown fox.",
        "Jumps over the lazy dog"
    };

    int size = sizeof(string)/sizeof(string[0]);
    
    // //before sorting
    // printf("\nThe string before sorting is: \n");
    // display(string, size);

    sortstring(string, size);

    // //after sorting
    // printf("\nThe string after sorting is : \n");
    // display(string, size);

    
}

void display(char str[][64], int n)
{
    for(int i = 0; i<n; i++)
    printf("(%d) -> %s\n", i+1, str[i]);
}

void sortstring(char str[][64], int n)
{   
    int logging = 1;
    if(logging)
    {
        printf("\nThe string before sorting is: \n");
        display(str, n);
    }

    int sorted = 0, iter = 0;
    while( ! sorted)
    {
        sorted = 1;
        iter++;
        for(int i = 0; i<n-1; ++i)
        {
            if(strcmp(str[i], str[i+1]) > 0)
            {
                char s[64];
                strcpy(s, str[i]);
                strcpy(str[i], str[i+1]);
                strcpy(str[i+1], s);
                sorted = 0;
            }
        }
        if(logging)
        {
            printf("\nPass %d\n", iter);
            display(str,n);
        }
    }
    if(logging)
    {
        printf("\nFully sorted. Took %d passes.\n", iter);
    }
    return;
}