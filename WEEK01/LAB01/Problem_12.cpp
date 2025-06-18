// Problem 12: Write a program that will Count and show the max frequency of a word in a string. 

// Problem 20: Write a C program to remove all repeated characters from a given string.
// Problem 10: Write a Program that Find and count the articles. 

#include<iostream>
#include<string.h>
#include<cctype>
#include<algorithm>
using namespace std;

void ToLowerCase(char * str){
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
    ToLowerCase(str);

    int i = 0;
    int freq[26] = {0};
    
    while (str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z'){
            int val = str[i] - 'a';
            freq[val]++;
        }
        i++;
    }
    // for (int j = 0; j < 26; j++){
    //     if(freq[j]> 0){
    //         char ch = 'a' + j;
    //         cout << ch << ": " << freq[j] << endl;
    //     }
    // }

    int * maxptr = max_element(freq, freq+26);

    int index = maxptr - freq;
    int val = *maxptr;

    char ch = 'a' + index;

    cout << ch << " max : " << val << endl;

    return 0;
} 