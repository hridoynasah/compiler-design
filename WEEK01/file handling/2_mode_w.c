#include<stdio.h>
int main()
{
    FILE * fp = NULL;

    // Opens the file for writing. Erases existing contents, creating a new empty file.
    fp = fopen("Hridoy.txt", "w");

    if(fp == NULL)
    {
        printf("Error opening file...\n");
    }
    else
    {
        printf("File opened successfully.");
        fclose(fp);
    }

    return 0;
}