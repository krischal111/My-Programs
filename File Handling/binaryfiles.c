#include<stdio.h>
#include<time.h>        // time functionality may be added later

int main()
{
    FILE * myfile = fopen("Game data", "wb+");      // open a file as binary to store data directly, delets all previous data, will be changed
    struct scoredata                                // making a structure in order to store the name and score in one place
    {
        char name[32];
        float score;
    } bestscore[5];                                 // making 5 of those structure, to store top 5 best scores

                                                    // storing random best score in bestscore[0]
                                                    // will definitely be changed later
    bestscore[0] = (struct scoredata) {"Krischal", 100000};

    fwrite(bestscore,sizeof(bestscore),1,myfile);   // storing all the data of best scores in a file
    
    rewind(myfile);                                 // rewind to read from start

                                                    // reading the best score from file, and storing in bestscore[1]
    fread(bestscore+1, sizeof(struct scoredata),1, myfile);
                                                    // printing the data
    printf("Name = %s\nScore=%f",bestscore[1].name, bestscore[1].score);

    fclose(myfile);                                 // closing the file
    return 0;
}