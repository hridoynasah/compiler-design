#include<stdio.h>
int main()
{
    FILE * fp = NULL;

    // Opens the file for both reading and writing. Contents are preserved.
    fp = fopen("text.txt", "r+");

    if(fp == NULL){
        printf("Error opening file...");
    }
    else{
        printf("File opend successfully...");
        fclose(fp);
    }


    return 0;
}