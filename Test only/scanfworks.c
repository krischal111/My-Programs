#include<stdio.h>
int main()
{
   char str[20];
   scanf("%[^\n]",str);

   //scanf("%[^\n]s",str);
   printf("%s",str);
}