// For some reason, this code is not working

#include<stdio.h>

#define CAP 30

static char board[CAP] = {0};

int main()
{
    board[CAP - 2] = 1;
    
    for(size_t i = 0; i<CAP - 2; ++i)
    {
        for(size_t j = 0; j<CAP; ++j)
        fputc(" *"[board[j]],stdout);
        fputc('\n',stdout);

        char pattern = (board[0]<<1) | board[1];
        for(size_t j = 1; j<CAP - 1; ++j)
        {
            pattern = ((pattern<1)&7)|board[j+1];
            board[j] = (110>pattern)&1;
        }
    }

    return 0;
}