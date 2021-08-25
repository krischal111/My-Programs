#include<stdio.h>
#include<conio.h>

int main()
{
    printf("Press 1 if you would like to check an alphabet is vowel or consonant.\n");
    printf("Press 2 if you would like to check ascii number of any character except digits.\n");
    char choice = getche();
    if(choice == '1')
    {
        char c;
        printf("Enter an alphabet. ");
        scanf(" %c",&c);
        if(('A'<=c && c <= 'Z')|| ('a'<=c && c <= 'z') )
        switch(c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            printf("It is a vowel letter. ");
            break;
            default:
            printf("It is a consonant letter. ");
        }
        else
        printf("Please supply an alphabet.");

    }
    else if(choice == '2')
    {
        char c;
        printf("Enter any character.");
        scanf(" %c",&c);
        if('0'<=c && c <= '9')
        printf("It is a digit. ");
        else
        printf("The ASCII VALUE is %d",c);
    }
    else
    printf("You pressed an invalid symbol.");
    return 0;
}