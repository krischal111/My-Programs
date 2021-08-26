#include <stdio.h>


int main()
{
    int a[10][10][10];
    printf("Size of a is          = %5d bytes. Address of a          is %10u. Value is = %u.\n",sizeof(a), &a, a);
    printf("Size of a[0] is       = %5d bytes. Address of a[0]       is %10u. Value is = %d.\n",sizeof(a[0]), &a[0], a[0]);
    printf("Size of a[0][0] is    = %5d bytes. Address of a[0][0]    is %10u. Value is = %u.\n",sizeof(a[0][0]), &a[0][0], a[0][0]);
    printf("Size of a[0][0][0] is = %5d bytes. Address of a[0][0][0] is %10u. Value is = %u.\n",sizeof(a[0][0][0]), &a[0][0][0], a[0][0][0]);
    return 0;
}