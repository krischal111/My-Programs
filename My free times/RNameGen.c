/*
A program to generate random name
Made by Krischal
Just for fun
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

// v = vowel, c = consonant, a = alphabet, n = number, l=alphanumeric, r = anything else
char randomcharacter(char);
char * randomname(char *, char, char);
//                name, gender, length        
/* Seriously, who uses name with more thatn 256 characters?
Even uvuvwevwevwe onyetenyevwe ugwemubwem ossas has at most 12 characters in his name*/

int main()
{
    srand(time(NULL));              // Randomizing with time as seed
    
    // Every variables needed are here
    char sex, length, name[257];
    name[256]='\0';                 // Failsafe

    // input part
    printf("\n       This is a random name generation program.\n\n");
    printf("Please enter a character [M=male's name, F=female's name] \nYour response = ");
    scanf("%c",&sex);

    if(sex>64 && sex<91)            // if capital letter
    sex+=32;                        // small it

    printf("Enter the number of characters in the name = ");
    {
        int len;
        scanf("%d",&len);
        length = (char) len;
    }

    // Output 1
    printf("\nThe 1st random name is '%s'\n", randomname(name, sex, length) );

    // Output 2
    randomname(name,sex,length);
    printf("The 2nd random name is '%s\n'",name);

    getch();
    return 0;
}

char * randomname(char *name, char sex, char length)
{
    name[length] = '\0';
    char vowelmode = 1;

    // Assuming default is female
    if(sex=='m')
    vowelmode = 0;

    for(int i = (int) length-1; i>=0; i--)
    {
        name[i]=randomcharacter((vowelmode?'v':'c'));   // Get a random character
        vowelmode = vowelmode?0:1;                        // Toggle vowelmode
    }

    name[0]-=32;                                        // Capitalizing the first character.
    return name;
}

char randomcharacter(char mode)
{
    //    printf("%d\n",1);///////////////////////////////////////1
    char ch=0;                        // To store output
    //    printf("%d\n",2);///////////////////////////////////////2
    if(64<mode && mode<91)          // if capital letter
    mode+=32;                       // small it
    
    switch(mode)
    {
        case 'v':                           // vowels only
            switch(rand()%5)
            {
                case 0: ch = 'a'; break;
                case 1: ch = 'e'; break;
                case 2: ch = 'i'; break;
                case 3: ch = 'o'; break;
                case 4: ch = 'u'; break;
            }
        break;

        case 'c':                           // consonants only
            do
            {
            ch = rand()%26 + 'a';    // generates an alphabet
            }while((ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u'));
        break;
            
        case 'a':                           // all alphabets
        ch = rand()%26+'a';
        break;

        case 'n':                           // numbers from 1 to 10
        ch = rand()%10 +'0';
        break;

        case 'l':                           // alphanumeric
        ch = rand()%3;                      // the alphabets ...
        if(ch>=1)   // If character mode enabled, also limits numbers to 1 third
        {
            ch = rand()%26+'a';
        }
        else                                // ... or the numbers
        ch = rand()%10+'0';
        break;

        case  'r':                          // ... any character
        default:
        ch = rand()%256;
        break;
    }
    return ch;    
}