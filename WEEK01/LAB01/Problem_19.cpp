#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string with leading spaces: ";
    cin.getline(str, 100);

    int i = 0;

    // Skip leading spaces, tabs, and newlines manually
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    // Copy the remaining characters to a new string
    char trimmed[100];
    int j = 0;
    while (str[i] != '\0') {
        trimmed[j] = str[i];
        i++;
        j++;
    }
    trimmed[j] = '\0';

    cout << "Trimmed string: \"" << trimmed << "\"" << endl;

    return 0;
}
