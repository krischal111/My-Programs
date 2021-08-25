/*wap which has 2 user defined function named process() and display(). read 2 numbers
in the main function pass into process, as argument add those numbers, and return the
sum, and use another function to display the sum
*/

#include<stdio.h>
#include<conio.h>

int process(int a, int b){
    return a + b;
}
int display(int sum){
    printf("The sum is %d",sum);
    return 0;
}
int main()
{
    int a, b, sum;
    printf("Enter two numbers = ");
    scanf("%d %d",&a,&b);
    sum = process(a,b);
    display(sum);
    getch();
    return 0;

}
