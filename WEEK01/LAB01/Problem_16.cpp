#include<iostream>
#include<string.h>
using namespace std;

int main() {
    char str[100], substr[100];
    cout << "Input the string: ";
    cin.getline(str, 100);

    cout << "Input the substring to be searched: ";
    cin.getline(substr, 100);

    char *token = strtok(str, " ");
    bool flag = false;

    while (token != NULL) {
        if (strcmp(token, substr) == 0) {
            flag = true;
            break;
        }
        token = strtok(NULL, " ");
    }

    if (flag) {
        cout << "The substring exists in the string." << endl;
    } else {
        cout << "The substring does not exist in the string." << endl;
    }

    return 0;
}
