#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int rows, cols;                         
    scanf("%d %d",&rows, &cols);            // inputting rows and columns
    if(rows>19 || cols > 19)                 // if they didn't match criteria
        return 0;                           // exit the programs, no strings attached
    
    char matrix[rows][cols], word[19];      // make a character matrix, and a word string
    for(int i = 0; i<rows; i++)
    for(int j = 0; j<cols; j++)
    scanf(" %c", &matrix[i][j]);             // input all the letters insoid the matrix

    scanf("%s",word);                       // scan the word
    int l = strlen(word);                   // lengh of the word
    int numofwords=0;
    
    for(int i = 0; i<rows; i++)
    for(int j = 0; j<cols; j++)
    {
        if(matrix[i][j] == word[0])         // if any words matches first letter
        {
            int condition = -1;             // preset the condition to be true, check if false later
            for (int k = 0; (k < l); k++)   // for operation in rows
                if (!( condition && matrix[(i+k)%rows][j] == word[k]) )
                {                           // condition: if word reaches end of row at side, comes back from front
                condition = 0;              // if even a letter don't match, ends checking
                break;
                }
            if(condition)
               numofwords++; 
            
            condition = -1;             // preset the condition to be true, check if false later
            for (int k = 0; (k < l); k++)   // for operation in cols
                if (!( condition && matrix[i][(j+k)%cols] == word[k]) )
                {                           // condition: if word reaches end of column at bottom, comes back from top
                condition = 0;              // if even a letter don't match, ends checking
                break;
                }
            if(condition)
               numofwords++; 
            
        }
    }
    printf("%d",numofwords);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
