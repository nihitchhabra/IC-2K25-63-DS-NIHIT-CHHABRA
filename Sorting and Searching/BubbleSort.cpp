#include <iostream>
#include <climits>
using namespace std;
void  bubblesort (int arr[], int n){
    for (int  i=0; i <n-1; ++i){
        bool swapped=false; 
        for (int j=0; j< n-i-1; ++j){
            if (arr[j] > arr [j+1]){
                std::swap(arr[j],arr[j+1]);
                swapped =true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

int main () {
 int arr[]={64, 34,25,12,22,11,19};
 int n=sizeof(arr)/sizeof(arr[0]);
 std::cout<<"original array:";
 for (int i=0; i<n; i++){
    std::cout<< arr[i] << " ";

 }  
 std::cout<< "\n";
 bubblesort(arr,n);
 std::cout<<"sorted array:";
 for (int i=0; i<n; i++){
    std::cout<< arr[i] << " ";

 }  
 std::cout<< "\n";
}