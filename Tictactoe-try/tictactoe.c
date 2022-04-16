#include <stdio.h>
#include <string.h>

struct game
{
    char cell[3][3];
};

void advancecolumn(int n)
{
    if(n<0)
    {
        for(int i=0; i>n; (--i, printf("\b")));
        return;
    }

    int tabs = n/8+1;
    int back = tabs*8 - n;
    if(back == 8)
    {
        back=0;
        tabs--;
    }
    for(int i=0; i<tabs; (i++, printf("\t")));
    for(int i=0; i<back; (i++, printf("\b")));
    return;
}

void display_game(char * cell)
{
    printf("             \n");
    for(int i = 0; i<3; ++i)
    {
        for(int j = 0; j<3; ++j)
        {
            char ch = *cell;
            if(ch == 1) ch = 'O';
            if(ch == 2) ch = 'X';
            if(ch == 0) ch = ' ';

            if(1)
            printf(" %c |", ch);

            if(1)
            {
                advancecolumn(-(4+j*4));
                advancecolumn(30 + j*7);
                if(ch != ' ')
                    printf("( %c ), ", ch);
                else
                    printf("(%d,%d), ", i+1, j+1);

                advancecolumn(j*4+4-(7+30+j*7));
            }
            cell++;            
        }
        printf("\b \n");
        
        if(i != 2)
        printf("---|---|--- \n");
    }
}

void display(char cell[3][3])
{
    display_game(&cell[0][0]);
}

// 0 if game needs to be continued
// 1 on least significant byte for game is over
// 0, 1, 2 on second least significant byte for draw (0) or (1 or 2) is the winner
int checkgame(char cell[3][3])
{
    int result = 1; // draw condition
  
    char a, b, c;

    // check for win if any
    {

        a = cell[0][0];
        b = cell[1][1];
        c = cell[2][2];
        if(a == b && b==c)
            if(a != 0)
                return result = (a<<8) + 1;

        a = cell[0][2];
        b = cell[1][1];
        c = cell[2][0];
        if(a == b && b==c)
            if(a != 0)
                return result = (a<<8) + 1;

        for(int i = 0; i<3; i++)
        {
            
            a = cell[i][0];
            b = cell[i][1];
            c = cell[i][2];
            if(a == b && b==c)
                if(a != 0)
                {
                    return result = (a<<8) + 1;
                    break;
                }

            a = cell[0][i];
            b = cell[1][i];
            c = cell[2][i];        
            if(a == b && b==c)
                if(a != 0)
                {
                    return result = (a<<8) + 1;
                    break;
                }
        }
    }

    // check for game continuation
    {
        for(int i = 0; i<3; i++)
        {
            a = cell[i][0];
            b = cell[i][1];
            c = cell[i][2];
            if(a == 0 || b == 0 || c == 0)
            return result = 0;
        }
    }
    return result;
}

int test1()
{
    struct game g;
    char check_cell[3][3] = 
    {
        {0,0,1},
        {0,1,0},
        {1,1,0}
    };

    memcpy(g.cell,check_cell,sizeof(check_cell));

    display(g.cell);

    int gamestatus = checkgame(g.cell);
    if(gamestatus)
    {
        switch((char)(gamestatus>>8))
        {
            case 1:
                printf("Player 1 won");
                break;
            case 2:
                printf("Player 2 won");
                break;
            case 0:
                printf("The game is draw");
                break;
        }
        printf("\n");
    }
    else
    {
        printf("Game continues");
        printf("\n");
    }

    return 0;
}

int test2()
{

    int a, b;
    struct game g;

    char start_cell[3][3] = 
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    memcpy(g.cell,start_cell,sizeof(start_cell));

    int gamestatus;
    char player = 1;
    char nextplayer = 2;


    while(!(gamestatus = checkgame(g.cell)))
    {

        display(g.cell);
        printf("Now, player %d has to make the turn.\n",player);

        again:
        printf("Enter you position = ");
        scanf("%d %d", &a, &b);
        a--; b--;
        if(
            (g.cell[a][b] != 0) ||
            a>2 || b>2 || a<0 || b<0
          )
        goto again;

        g.cell[a][b] = player;
        
        printf("Player %d made the turn.\n",player);
        // next player's turn
        int temmpp = player;
        player = nextplayer;
        nextplayer = temmpp;
    }

    display(g.cell);

    if(gamestatus)
    {
        switch((char)(gamestatus>>8))
        {
            case 1:
                printf("Player 1 won");
                break;
            case 2:
                printf("Player 2 won");
                break;
            case 0:
                printf("The game is draw");
                break;
        }
        printf("\n");
    }

    return 0;
}

int main()
{
    test2();
    return 0;
}