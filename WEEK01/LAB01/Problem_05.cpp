#include <iostream>
using namespace std;

int main() {
    char a[100], b[100];
    cin >> a >> b;

    int i = 0;
    while (true) {
        if (a[i] == '\0' && b[i] == '\0') {
            cout << "Same" << endl;
            break;
        }
        else if (a[i] == '\0') {
            cout << "A choto" << endl;
            break;
        }
        else if (b[i] == '\0') {
            cout << "B choto" << endl;
            break;
        }

        if (a[i] == b[i]) {
            i++;
        }
        else if (a[i] < b[i]) {
            cout << "A choto" << endl;
            break;
        }
        else {
            cout << "B choto" << endl;
            break;
        }
    }

    return 0;
}
