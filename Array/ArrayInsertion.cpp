#include <iostream>
using namespace std;

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; 
    int pos, element;
    
    cout << "Original array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\nEnter position where you want to insert (0 to " << n << "): ";
    cin >> pos;
    cout << "Enter element to insert: ";
    cin >> element;
    
    for(int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[pos] = element;
    n++;
    
    cout << "Array after insertion:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}