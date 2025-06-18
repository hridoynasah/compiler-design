// Problem 10: Write a Program that Find and count the articles. 

#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;

void toLowerCase(char * str){
    int i = 0;
    while(str[i]){
        str[i] = tolower(str[i]);
        i++;
    }
}

int main(){

    char str[100];
    cout << "Enter input: ";

    cin.getline(str, 100);

    int i = 0;
    int countA = 0, countAn = 0, countThe = 0;
    toLowerCase(str);
    char * token = strtok(str, " \n\t");


    while (token != NULL){
        if(strcmp(token, "a") == 0){
            countA++;
        }else if(strcmp(token, "an") == 0){
            countAn++;
        }else if(strcmp(token, "the") == 0){
            countThe++;
        }
        token = strtok(NULL, " \n\t");
    }
    
    cout << "'a' appears " << countA << " times" << endl;
    cout << "'an' appears " << countAn << " times" << endl;
    cout << "'the' appears " << countThe << " times" << endl;

    return 0;
}