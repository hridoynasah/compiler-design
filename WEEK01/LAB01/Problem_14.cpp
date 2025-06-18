// Problem 14: Write a program to Show the initial. 
#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;

int main(){

    char str[100];
    cout << "Enter your full name: ";
    cin.getline(str,100);

    char * name = strtok(str, " ");

    while(name != NULL){
        cout << name[0];
        name = strtok(NULL, " ");
    }

    return 0;
}
