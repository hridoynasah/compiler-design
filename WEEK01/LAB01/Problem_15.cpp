// Problem 15: Write a program in C to extract a substring from a given string. 

#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;

int main(){

    char str[100];
    int pos, len;
    cout << "Enter the string: ";
    cin.getline(str,100);

    cout << "Enter the position of the string: ";
    cin >> pos;

    cout << "Enter the length of the string: ";
    cin >> len;
    int sub_len = pos + len;
    for(int i = pos; i <= sub_len; i++){
        cout << str[i];
    }

    return 0;
}
