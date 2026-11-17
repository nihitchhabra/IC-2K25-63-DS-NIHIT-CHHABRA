#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    int mat[3][3] = {
        {0, 0, 5},
        {0, 0, 0},
        {1, 0, 0}
    };
    
    int totalElements = rows * cols;
    int zeroCount = 0;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    
    cout << "Total elements: " << totalElements << "\n";
    cout << "Zero elements count: " << zeroCount << "\n";
    
    // A matrix is sparse if the number of zero elements > total elements / 2
    if(zeroCount > totalElements / 2) {
        cout << "The given matrix is a Sparse Matrix.\n";
    } else {
        cout << "The given matrix is NOT a Sparse Matrix.\n";
    }
    
    return 0;
}