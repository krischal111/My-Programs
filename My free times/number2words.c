#include<stdio.h>
#include<string.h>
#include<windows.h>

int main()
{
    long number;
    scanf("%ld",&number);
    char numname[183];
    char numname[182]=0;
    printf("%s",num2name(numname,number));
    
}

char * num2name(char * outstring, long innumber)
{
    int numdigits=0;
    long rev=0;
    char getname[15];

    long temp = innumber;
    do{
        numdigits++;
        rev=rev*10+temp%10;
        temp/=10;
    }while(temp>0);
    
    temp = innumber;
    int digits[numdigits];
    for(int i = 0; i<numdigits; i++)
    {
        digits[i] = temp%10;
        temp/=10;
    }

    
    
}

char * numblockname(char *outstring, long innumber)
{
    int numdigits=0;
    int digit100 = (innumber%1000)/100;
    int digit10 = (innumber%100)/10;
    int digit1 = (innumber%10)/10;
    char getname[15];
    
    if(digit100!=0)
    {
    digitname(getname,digit100);
    strcpy(outstring, getname);
    strcat(outstring," hundred ");
    }

    if(!(digit10==0 && digit1==0))
    {
        if(digit10==1)
        {
            digitname(getname,digit10*10+digit1); // 11 = eleven
            strcat(outstring,getname);
        }
        else
        {
            if(digit10>1)
            {
            digitname(getname,digit10*10); // 70 = seventy
            strcat(outstring,getname);
            }

            if(digit1!=0)
            {
            strcat(outstring,"-");
            digitname(getname,digit1);      // 7 = seven
            strcat(outstring,getname);
            }
        }
    }
    return outstring;
}

char * digitname(char * outstring, long innumber)
{
    switch(innumber)
    {
        case 0:
        strcpy(outstring, "zero");
        break;

        case 1:
        strcpy(outstring, "one");
        break;

        case 2:
        strcpy(outstring, "two");
        break;

        case 3:
        strcpy(outstring, "three");
        break;

        case 4:
        strcpy(outstring, "four");
        break;

        case 5:
        strcpy(outstring, "five");
        break;

        case 6:
        strcpy(outstring, "six");
        break;

        case 7:
        strcpy(outstring, "seven");
        break;

        case 8:
        strcpy(outstring, "eight");
        break;

        case 9:
        strcpy(outstring, "nine");
        break;

        case 10:
        strcpy(outstring, "ten");
        break;

        case 11:
        strcpy(outstring, "eleven");
        break;

        case 12:
        strcpy(outstring, "twelve");
        break;

        case 13:
        strcpy(outstring, "thirteen");
        break;

        case 14:
        strcpy(outstring, "fourteen");
        break;

        case 15:
        strcpy(outstring, "fifteen");
        break;

        case 16:
        strcpy(outstring, "sixteen");
        break;

        case 17:
        strcpy(outstring, "seventeen");
        break;

        case 18:
        strcpy(outstring, "eighteen");
        break;

        case 19:
        strcpy(outstring, "nineteen");
        break;

        case 20:
        strcpy(outstring, "twenty");
        break;

        case 30:
        strcpy(outstring, "thirty");
        break;

        case 40:
        strcpy(outstring, "forty");
        break;

        case 50:
        strcpy(outstring, "fifty");
        break;

        case 60:
        strcpy(outstring, "sixty");
        break;

        case 70:
        strcpy(outstring, "seventy");
        break;

        case 80:
        strcpy(outstring, "eighty");
        break;

        case 90:
        strcpy(outstring, "ninety");
        break;

        case 100:
        strcpy(outstring, "hundred");
        break;

        case 1000:
        strcpy(outstring, "thousand");
        break;

        case 1000000:
        strcpy(outstring, "million");
        break;

        case 1000000000:
        strcpy(outstring, "billion");
        break;

        case 1000000000000:
        strcpy(outstring, "trillion");
        break;

        case 1000000000000000:
        strcpy(outstring, "quadrillion");
        break;

        case 1000000000000000000:
        strcpy(outstring, "quintillion");
        break;
    }
    return outstring;
}