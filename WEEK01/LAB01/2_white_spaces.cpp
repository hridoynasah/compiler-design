#include<iostream>
using namespace std;

int main(){

    char str[100];
    cout << "Enter input: ";
    cin.getline(str, 100);

    int i = 0;
    int count = 0;
    while (str[i] != '\0'){
        if(str[i] == ' '){
            count++;
        }
        i++;
    }

    cout << "Number of white spaces: " << count;

    return 0;
}