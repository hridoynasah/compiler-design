// Problem 09: Write a C program to convert uppercase string to lowercase. 
// Problem 08: Write a program that will tokenize a string.

#include<iostream>
using namespace std;

int main(){

    char str[100];
    cout << "Enter input: ";

    cin.getline(str, 100);

    int i = 0;
    while (str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            int val = 'a' - 'A'; 
            str[i] += val;
        }else{
            str[i] = str[i];
        }
        i++;
    }
    
    cout << "Lower case String: \n" << str;

    return 0;
}