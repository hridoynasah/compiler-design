#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    char result[100];  // to store the unique characters
    int i = 0, j = 0;
    bool isDuplicate;

    while (str[i] != '\0') {
        isDuplicate = false;

        // Check if str[i] already exists in result[]
        for (int k = 0; k < j; k++) {
            if (str[i] == result[k]) {
                isDuplicate = true;
                break;
            }
        }

        // If not duplicate, add to result
        if (!isDuplicate) {
            result[j] = str[i];
            j++;
        }

        i++;
    }

    result[j] = '\0';  // null-terminate the result string

    cout << "String after removing duplicates: " << result << endl;

    return 0;
}
