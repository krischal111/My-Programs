#include <stdio.h>

int len(const char * const s)
{
    if(!*s) return 0;
    const char * ss = s;
    while(*(++ss));
    return ss-s;
}
int main()
{
    char string[] = "Abcdefghijklmnopqrstuvwxyz    0123456789";
    printf("Length of string = %d\n",len(string));

}