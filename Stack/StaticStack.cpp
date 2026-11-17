#include <iostream>

using namespace std;

class Stack {
    int top;
    int arr[100];
    int capacity;

public:
    Stack(int size = 100) {
        top = -1;
        capacity = size;
    }

    void push(int x) {
        if (top >= capacity - 1) {
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top < 0) {
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            return -1;
        }
        return arr[top];
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.display();
    return 0;
}