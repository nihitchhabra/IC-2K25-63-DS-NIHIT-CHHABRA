#include <iostream>

using namespace std;

int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = 5;
    int x = 10;
    int result = sequentialSearch(arr, n, x);
    cout << result;
    return 0;
}