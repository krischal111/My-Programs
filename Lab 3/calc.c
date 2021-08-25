// Calculator program
#include<conio.h>
#include<stdio.h>
int main(){
    int a, b, res;
    char opr;
    printf("Enter two number separated by space = ");
    scanf("%d%d",&a,&b);
    printf("Enter the operator (any of + - * /). ->");
    scanf(" %c",&opr);

    switch (opr)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    default:
        printf("No match found");
        goto end;
        break;
    }
    printf("Your answer is %d %c %d = %d",a,opr,b,res);
    end:
    getch();
    return 0;
}
