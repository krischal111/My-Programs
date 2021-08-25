/*WAP to read marks of n students and print out top five .*/

#include<stdio.h>

int main()
{
    char n;
    printf("Enter the number of students = ");
    scanf("%d",&n);
    float marks[n];
    int dord[n];        // Descending order (stores index only, not actual values)

    for(int i = 0; i<n; i++)
    {
        printf("Marks of %dth student = ",i+1);
        scanf("%f",&marks[i]);
        dord[i]=i;
    }

    printf("The top %d marks are:\t",(n>5)?5:n);        // sometimes there can be students less than 5
    for(int i = 0; i<5; i++)        // Just 5 iteration enough for top 5 using selection sort
    {
        if(n<5)
        if(i==n)
        break;
        for(int j = i+1; j<n; j++)
        {
            if(marks[dord[i]]<marks[dord[j]])
            {
                int tmp = dord[i];
                dord[i]=dord[j];
                dord[j]=tmp;
            }
        }
        printf("%.2f,\t",marks[dord[i]]);
    }

}