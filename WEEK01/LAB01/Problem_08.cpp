// Problem 08: Write a program that will tokenize a string.

#include<iostream>
using namespace std;

int main(){

    char str[100], tokenize_str[100];
    cout << "Enter input: ";

    cin.getline(str, 100);

    int i = 0;
    while (str[i] != '\0'){
        if(str[i] == ' '){
            tokenize_str[i] = '\n';
        }else{
            tokenize_str[i] = str[i];
        }
        i++;
    }
    tokenize_str[i] = '\0';
    cout << "Tokenized String: \n" << tokenize_str;

    return 0;
}