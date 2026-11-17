#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos;
    
    cout << "Original array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\nEnter index position to delete (0 to " << n - 1 << "): ";
    cin >> pos;
    
    if(pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return 0;
    }
 
    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    n--;
    
    cout << "Array after deletion:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}