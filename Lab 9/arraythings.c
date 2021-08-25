#include <stdio.h>

int main()
{
    int a[10][10][10];
    printf("Size of a is = %d bytes. Address of a is %u\n",sizeof(a));
    printf("Size of a[0] is = %d bytes. Address of a[0] is %u\n",sizeof(a[0]));
    printf("Size of a[0][0] is = %d bytes. Address of a[0][0] is %u\n",sizeof(a[0][0]));
    printf("Size of a[0][0][0] is = %d bytes. Address of a[0][0][0] is %u\n",sizeof(a[0][0][0]));
    return 0;
}