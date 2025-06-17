// Problem 04: Write a program in C to print individual characters of a string in reverse order.

#include<iostream>
using namespace std;

int main(){

    char str[100], output_str[100];
    cout << "Enter input: ";
    cin.getline(str, 100);

    // length of the string
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    len = len-1;
    int j = 0;
    while(str[len] >= 0){
        output_str[j] = str[len];
        len--;
        j++;
    }

    cout << "Output: " << output_str;

    return 0;
}