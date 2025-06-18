// Problem 07: Write a program to copy one string to another string.

#include<iostream>
using namespace std;

int main(){

    char str[100], copied_str[100];
    cout << "Enter input: ";

    cin.getline(str, 100);

    int i = 0;
    while (str[i] != '\0'){
        copied_str[i] = str[i];
        i++;
    }
    copied_str[i] = '\0';
    cout << "Copied String: " << copied_str;

    return 0;
}