#include<stdio.h>
#include<windows.h>
int main()
{
    unsigned int number=0;
    char inversedigits=32;
    printf("\nEnter a binary number = ");

    while(1)
    {
        if(GetAsyncKeyState(49)) // A.K.A.  1
        {
            //Set 1, starting from the MSB
        number|= (  1<<(--inversedigits)  );
        printf("1");
        }

        if(GetAsyncKeyState(48)) // A.K.A.  0
        {
            //There are already 0s so do not worry
        --inversedigits;
        printf("0");
        }
        if(GetAsyncKeyState(VK_RETURN)||inversedigits==0)
        {
        printf("\n");
        break;
        }
        Sleep(100);
    }

    number= number>>(inversedigits);
    printf("Your number in decimal is %u",number);
    Sleep(200);
    while(!GetAsyncKeyState(VK_RETURN))     
    ;
}