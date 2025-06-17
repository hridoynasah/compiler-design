#include<iostream>
using namespace std;
int main()
{
    int num;
    char str[100];
    cout << "Enter the number: ";
    cin >> num;
    cin.ignore();

    cout << "Enter a line: ";
    cin.getline(str, 100);
    
    cout << "Number: " << num << endl;
    cout << "String: " << str << endl;

    return 0;
}