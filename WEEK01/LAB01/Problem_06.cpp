// Problem 06: Write a program to count the total number of alphabets, digits and special characters in a string. 

#include<iostream>
using namespace std;

int main(){

    char str[100];
    cout << "Enter the input: ";
    cin.getline(str, 100);

    int i = 0;
    int alpha = 0, dig = 0, sp = 0;
    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'){
            alpha++;
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            dig++;
        }
        else{
            sp++;
        }
        i++;
    }

    cout << "Alphabets: " << alpha << endl;
    cout << "Digits: " << dig << endl;
    cout << "Special Characters: " << sp << endl;

    return 0;
}