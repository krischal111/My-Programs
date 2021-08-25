#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include<stdlib.h>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

//Declaration of global variables
enum color {background,cyan,yellow,purple,green,blue,red,orange, lightgray, darkgray,black};
const unsigned char softblock = 176, semisoftblock=177, semisolidblock=178, solidblock = 219;     // ░▒▓█
const unsigned char horizontal2border = 205,  vertical2border  = 186;                             //  ═ ║
const unsigned char topleft2border    = 201,  topmid2border    = 203,   topright2border     = 187;//  ╔╦╗
const unsigned char leftmid2border    = 204,  centre2border    = 206,   rightmid2border     = 185;//  ╠╬╣
const unsigned char bottomleft2border = 200,  bottommid2border = 202,   bottomright2border  = 188;//  ╚╩╝
const unsigned char horizontalborder  = 196,  verticalborder   = 179;                             //  ─ │
const unsigned char topleftborder     = 218,  topmidborder     = 194,   toprightborder      = 191;//  ┌┬┐
const unsigned char leftmidborder     = 195,  centreborder     = 197,   rightmidborder      = 180;//  ├┼┤
const unsigned char bottomleftborder  = 192,  bottommidborder  = 193,   bottomrightborder   = 217;//  └┴┘

//7 tetrominos 2 coordinates of centres, probably won't be used
const char Tetromino2centres[7][2] =
{
    {4,4},//I
    {3,3},//J
    {3,3},//L
    {2,4},//O
    {3,3},//S
    {3,3},//T
    {3,3},//Z
};

/* 7 diff tetrominos, each have 4 rotations, 
each have 4 blocks, each have 2 values for coordinates
*/
const char Tetrominos[7][4][4][2] = 
{// Tetramino types
    // Type I complete
    {// Rotations
        // 4 Blocks rotation 0
        {   //Coordinates
            {1,0},
            {1,1},
            {1,2},
            {13}
        },
        // 4 Blocks rotation 1
        {   //Coordinates
            {0,2},
            {1,2},
            {2,2},
            {3,2}
        },
        // 4 Blocks rotation 2
        {   //Coordinates
            {2,0},
            {2,1},
            {2,2},
            {2,3}
        },
        // 4 Blocks rotation 3
        {   //Coordinates
            {0,1},
            {1,1},
            {2,1},
            {3,1}
        }
    },
    // Type J complete
    {// Rotations
        // 4 Blocks rotation 0
        {   //Coordinates
            {0,0},
            {1,0},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 1
        {   //Coordinates
            {0,1},
            {0,2},
            {1,1},
            {2,1}
        },
        // 4 Blocks rotation 2
        {   //Coordinates
            {1,0},
            {1,1},
            {1,2},
            {2,2}
        },
        // 4 Blocks rotation 3
        {   //Coordinates
            {0,1},
            {1,1},
            {2,0},
            {2,1}
        },
    },
    // Type L complete
    {// Rotations
        // 4 Blocks rotation 0
        {   //Coordinates
            {0,0},
            {1,0},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 1
        {   //Coordinates
            {0,1},
            {1,1},
            {2,1},
            {2,2}
        },
        // 4 Blocks rotation 2
        {   //Coordinates
            {1,0},
            {1,1},
            {1,2},
            {2,0}
        },
        // 4 Blocks rotation 3
        {   //Coordinates
            {0,0},
            {0,1},
            {1,1},
            {2,1}
        },
    },
    // Type O complete
    {// Rotations
        // 4 Blocks rotation 0
        {   //Coordinates 2 3 5 6
            {0,1},
            {0,2},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 1
        {   //Coordinates 2 3 5 6
            {0,1},
            {0,2},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 2
        {   //Coordinates 2 3 5 6
            {0,1},
            {0,2},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 3
        {   //Coordinates 2 3 5 6
            {0,1},
            {0,2},
            {1,1},
            {1,2}
        },
    },
    // Type S complete
    {// Rotations
        // 4 Blocks rotation 0
        {   //Coordinates 2 3 4 5
            {0,1},
            {0,2},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 1
        {   //Coordinates 2 5 6 9
            {0,1},
            {1,1},
            {1,2},
            {2,2}
        },
        // 4 Blocks rotation 2
        {   //Coordinates 5 6 7 8
            {1,1},
            {1,2},
            {2,0},
            {2,1}
        },
        // 4 Blocks rotation 3
        {   //Coordinates 1 4 5 8
            {0,0},
            {1,0},
            {1,1},
            {2,1}
        },
    },
    // Type T complete
    {// Rotations
        // 4 Blocks rotation 0
        {   //Coordinates 2 4 5 6
            {0,1},
            {1,0},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 1
        {   //Coordinates 2 5 6 8
            {0,1},
            {1,1},
            {1,2},
            {2,1}
        },
        // 4 Blocks rotation 2
        {   //Coordinates 4 5 6 8
            {1,0},
            {1,1},
            {1,2},
            {2,1}
        },
        // 4 Blocks rotation 3
        {   //Coordinates 2 4 5 8
            {0,1},
            {1,0},
            {1,1},
            {2,1}
        },
    },
    // Type Z complete
    {// Rotations
        // 4 Blocks rotation 0
        {   //Coordinates 1 2 5 6
            {0,0},
            {0,1},
            {1,1},
            {1,2}
        },
        // 4 Blocks rotation 1
        {   //Coordinates 3 5 6 8
            {0,2},
            {1,1},
            {1,2},
            {2,1}
        },
        // 4 Blocks rotation 2
        {   //Coordinates 4 5 8 9
            {1,0},
            {1,1},
            {2,1},
            {2,2}
        },
        // 4 Blocks rotation 3
        {   //Coordinates 2 4 5 7
            {0,1},
            {1,0},
            {1,1},
            {2,0}
        },
    }
};

//Declatration of structures
struct Tetrisgrid{
    bool grid[40][10];
    enum color blockcolor[40][10];
    };
struct Tetrisblocks{
    char blocks[5];
    // 0 for hold, 1 for current, 2,3,4 are next blocks
    char rotatevalue;
    // 0 for no rotation, 1, 2, and 3 are multiples of clockwise 90degree rotation
};


//Declaration of function used later
void draweverything(struct Tetrisgrid, long, int, struct Tetrisblocks);
//                      Tetris grid, score, level, hold, now and next 3 blocks
void drawblock(int x, int y, int blocksize, int blockcolor);
int colorvalue(enum color colour);
void cls();



/*
//\\      //\\     //\\     || ||\\    ||    /(  )\
|| \\    // ||    //  \\    || || \\   ||   //    \\
||  \\  //  ||   //====\\   || ||  \\  ||   [(    )]
||   \\//   ||  //      \\  || ||   \\ ||   \\    //
||    \/    || //        \\ || ||    \\||    \(  )/
*/
int main()
{  
    //Declaration part
    bool escapepressed=0;
    char keypress;
    struct Tetrisgrid grid1;
    struct Tetrisblocks blocks1;
    long score = 0;
    int level = 5;

    char counter;
    while(! escapepressed)
    {
        escapepressed = GetAsyncKeyState(VK_ESCAPE);
        Sleep(1000/level);
        counter++;

        grid1.grid[counter/10][counter%10] = 1;
        grid1.grid[(unsigned int) (counter-1)/10][(unsigned int) (counter-1)] = 0;
        score+=level;
        blocks1.blocks[1]=1;
        blocks1.rotatevalue=0;
        draweverything(grid1,score,level,blocks1);
        if(escapepressed)
        {
            printf("You pressed ESCAPE key, now wait a second.");
            Sleep(2000);
            printf("%d",keypress);
            system("CLS");
        }
    }

    return 0;
}


void draweverything(struct Tetrisgrid grid,long score, int level, struct Tetrisblocks blocks)
{
    char wholepicture[1000];
    int counter=0;
    wholepicture[counter++]=topleftborder;          // ┌
    for(int i = 0; i<20;i++)                        // Double of 10 times
        wholepicture[counter++]=horizontalborder;   // ─────
    wholepicture[counter++]=toprightborder;         // ┐    combined: ┌──────┐
    wholepicture[counter++]='\n';

for(int i = 0; i<40; i++)
{
    wholepicture[counter++]=verticalborder;     // │ and ...
    for(int j = 0; j<10; j++)
    {
        wholepicture[counter++]=softblock;
        wholepicture[counter++]=softblock;
    if(grid.grid[i][j])
        {
            counter-=2;
            wholepicture[counter++]=semisolidblock;
            wholepicture[counter++]=semisolidblock;
        }    
    }
    wholepicture[counter++]=verticalborder;
    wholepicture[counter++]='\n';                  // ... and │ next line
}
    wholepicture[counter++]=bottomleftborder;       // └
    for(int i = 0; i<20;i++)                        // Double of 10 times
        wholepicture[counter++]=horizontalborder;   // ─────
    wholepicture[counter++]=bottomrightborder;
    wholepicture[counter++]='\n';                   // ┘    combined: └──────┘
    wholepicture[counter++]='\0';
    
    cls();
    printf("%s",wholepicture);
    printf("Score: %-10ldLevel: %d",score,level);
}

void drawblock(int x, int y, int blocksize, int blockcolor)
{
    //rectangle(blocksize*x,blocksize*y,blocksize*x+x, blocksize*y+y);
}
int colorvalue(enum color colour)
{
    switch (colour)
    {
    case background:return -1;   break;
    case cyan:      return 3;   break;
    case yellow:    return 14;  break;
    case purple:    return 5;   break;
    case green:     return 2;   break;
    case blue:      return 1;   break;
    case red:       return 4;   break;
    case orange:    return 12;  break;
    case lightgray: return 7;   break;
    case darkgray:  return 8;   break;
    default:        return 0;    break;
    }
}
void cls()
{
    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // std::cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // std::cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    fflush(stdin);

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
    
    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
}

