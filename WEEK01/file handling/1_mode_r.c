#include<stdio.h>

int main(){

    FILE * fp = NULL;

    // Opens the file for reading. Contents are preserved.
    fp = fopen("Hridoy.txt", "r");

    if (fp == NULL){
        printf("Error while opening the file...\n");
    }else{
        printf("File opend successfully...\n");
        fclose(fp);
    }


    return 0;
}