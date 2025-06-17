// Problem 03: Write a program that will remove white space from a string.

#include<iostream>
using namespace std;

int main(){

    char str[100], output_str[100];
    cout << "Enter input: ";
    cin.getline(str, 100);

    int i = 0, j = 0;
    while(str[i] != '\0'){
        if(str[i] != ' '){
            output_str[j] = str[i];
            j++;
        }
        i++;
    }
    output_str[j] = '\0';
    cout << "Output: " << output_str;

    return 0;
}