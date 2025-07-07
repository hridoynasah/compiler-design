#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int arr[] = {5, 12, 7, 9, 15, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* maxPtr = max_element(arr, arr + n);
    int maxIndex = maxPtr - arr;
    int maxValue = *maxPtr;

    cout << "Max value: " << maxValue << endl;
    cout << "Index: " << maxIndex << endl;

    return 0;
}
