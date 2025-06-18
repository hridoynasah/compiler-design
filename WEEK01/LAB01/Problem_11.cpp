#include <iostream>
using namespace std;

bool isValidIdentifier(char str[]) {
    // Check if the first character is a letter or underscore
    if (!((str[0] >= 'a' && str[0] <= 'z') ||
          (str[0] >= 'A' && str[0] <= 'Z') ||
           str[0] == '_')) {
        return false;
    }

    // Check the rest of the characters
    for (int i = 1; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9') ||
               str[i] == '_')) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    char identifier[100];

    cout << "Enter number of identifiers: ";
    cin >> n;
    cin.ignore();  // to consume the newline after the number

    while (n--) {
        cout << "Enter identifier: ";
        cin.getline(identifier, 100);

        if (isValidIdentifier(identifier)) {
            cout << "\"" << identifier << "\" is a valid identifier." << endl;
        } else {
            cout << "\"" << identifier << "\" is not a valid identifier." << endl;
        }
    }

    return 0;
}
