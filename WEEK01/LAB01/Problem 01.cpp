//  Problem 01: Write a program that will count the length of a string.
#include<iostream>
using namespace std;

int main(){
    char str[100];
    cin.getline(str, 100);
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    cout << "Length of the string: " << len;
    return 0;
}