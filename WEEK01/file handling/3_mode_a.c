#include<stdio.h>
int main()
{
    FILE * fp = NULL;

    // Opens the file for appending. Contents are preserved, and new data is added to the end.
    fp = fopen("Hridoy.txt", "a");

    if(fp == NULL){
        printf("Error opening file...");
    }
    else{
        printf("File opend successfully...");
        fclose(fp);
    }


    return 0;
}