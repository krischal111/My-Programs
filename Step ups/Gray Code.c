#include<stdio.h>
#include<windows.h>
const unsigned int one=1;
const unsigned int zero=0;
const int allones=-1;

_Bool paritycheck(unsigned long int, char size);

int main()
{
    unsigned int number=0,parity,graycode=0;
    char  uintsize=8*sizeof(unsigned int);
    char inversedigits=uintsize, inversegraydigits=uintsize;
    printf("\nEnter a binary number = ");

    while(1)
    {
        if(GetAsyncKeyState(49)) // A.K.A.  1 
        {
            //Set 1, starting from the MSB
        number|= (  one<<(--inversedigits)  );
        printf("1");
        }

        if(GetAsyncKeyState(48)) // A.K.A.  0 
        {
            //There are already 0s so do not worry
        --inversedigits;
        printf("0");
        }
        if(GetAsyncKeyState(VK_RETURN)||inversedigits==0) // 
        {
        printf("\n");
        break;
        }
        if(GetAsyncKeyState(8))//
        {
            if(inversedigits<uintsize)//
            {
            printf("\b \b"); //
            number&= allones^(one<<(inversedigits++)); //bitwise ANDing with a single 0 at our place
            //In other words, sets 0 at out desired place, and leave others unchanged
            }
        }
        Sleep(100);
    }
    
    /* Moved this algorithm to a recursive function paritycheck
    paritycheck=number;
    paritycheck^=paritycheck>>16;
        paritycheck^=paritycheck>>8;
            paritycheck^=paritycheck>>4;
                paritycheck^=paritycheck>>2;
                    paritycheck^=paritycheck>>1;
    paritycheck&=1;     // Erases all other bits except the LSB
    */

    // Parity check remains same as long as no of 1's are same, so checking that before shifting
    parity = (paritycheck(number,uintsize>>1))? 1 : 0 ;
    
    graycode |= ((one<<(--inversegraydigits))&number); // copies the first digit from number
    for(char i = uintsize; i> inversedigits+1; i--) // first iteration ran outside so just iterate once less
    {
        --inversegraydigits;
        graycode |=   ( (one&(number>>inversegraydigits)) ^ (one&(number>>(inversegraydigits+1))) )<<inversegraydigits;
    }
    graycode=graycode>>(inversegraydigits);

    number= number>>(inversedigits);
    printf("Your number in decimal is %u and parity is %d",number,parity);
    printf("\nAnd that in a gray code is ",graycode);
    for(int i = uintsize-1-inversegraydigits;i>=0;i--)
    {
        printf("%d", (graycode>>i)&1);
    }
    Sleep(200);
    while(!GetAsyncKeyState(VK_RETURN))     
    ;
}

_Bool paritycheck(unsigned long number, char size)
{
    if(size==1)
    return ((number&1)==1);
    // Real operation below:
    unsigned long parity=number;
    parity = paritycheck(  (parity >> (size))   ,   size>>1);
}