#include<stdio.h>
int main()
{
    FILE * fp = NULL;

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