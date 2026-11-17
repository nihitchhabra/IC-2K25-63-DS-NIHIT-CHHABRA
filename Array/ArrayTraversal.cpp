#include <iostream>
using namespace std;

int main() {
    int arr[5];
    
    cout << "Enter 5 integer elements:\n";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    cout << "\nDisplaying array elements:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Element at index " << i << " = " << arr[i] << "\n";
    }
    
    return 0;
}