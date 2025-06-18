// Problem 13: Write a C Program that takes 3 Characters and shows the Next 3 Characters. 

#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;

int main(){

    char str[100];
    cout << "Enter input: ";

    cin.getline(str, 100);
    int i = 0;

    while(str[i] != '\0'){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            if(str[i] > 'W'){
                char a = str[i] - 23;
                cout << a ;
            }else{
                char b = str[i] + 3;
                cout << b;
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z'){
            if(str[i] > 'w'){
                char c = str[i] - 23;
                cout << c ;
            }else{
                char d = str[i] + 3;
                cout << d;
            }
        }
        else {
            cout << str[i];
        }
        i++;
    }
    
    return 0;
}